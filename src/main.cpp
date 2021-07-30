/**
 * ESP32 / ESP8266 Arduino Tutorial:4. Protocol Buffers (https://www.dfrobot.com/blog-1161.html)
 * ESP32 / ESP8266 Arduino Tutorial:5. Protocol Buffers: messages with strings (https://www.dfrobot.com/blog-1162.html)
 * Official Nanopb: Basic concepts: https://jpa.kapsi.fi/nanopb/docs/concepts.html#id10
 */
#include <Arduino.h>
#include <pb.h>
#include <pb_common.h>
#include <pb_decode.h>
#include <pb_encode.h>

#include "protofiles/test.pb.h"

char * strTemp;

bool encode_string(pb_ostream_t *stream, const pb_field_t *field, void *const *arg) {
    // char *str = "Hello, World!";
    // char *str = *arg;
    char *str = strTemp;
    if (!pb_encode_tag_for_field(stream, field))
        return false;

    return pb_encode_string(stream, (uint8_t *)str, strlen(str));
}

bool decode_string(pb_istream_t *stream, const pb_field_t *field, void **arg) {
    uint8_t buffer[1024] = {0};

    /* We could read block-by-block to avoid the large buffer... */
    if (stream->bytes_left > sizeof(buffer) - 1)
        return false;

    if (!pb_read(stream, buffer, stream->bytes_left))
        return false;

    /* Print the string, in format comparable with protoc --decode.
     * Format comes from the arg defined in main().
     */
    Serial.print("Message.test_string: ");
    Serial.println((char *)buffer);
    //printf((char*)*arg, buffer);
    return true;
}

void setup() {
    Serial.begin(115200);

    uint8_t buffer[1280];
    bool status;
    size_t message_length;

    strTemp = (char *) malloc(sizeof(char) * 20);
    strTemp = "mantap";

    /* ENCODING */
    {
        TestMessage message = TestMessage_init_zero;
        message.test_number = 540;
        message.test_number2 = 123;
        message.test_number3 = 456;
        message.test_string.funcs.encode = encode_string;

        pb_ostream_t ostream = pb_ostream_from_buffer(buffer, sizeof(buffer));
        status = pb_encode(&ostream, TestMessage_fields, &message);

        if (!status) {
            Serial.println("Failed to encode");
            return;
        }

        message_length = ostream.bytes_written;

        Serial.print("Message bytes: ");
        Serial.println(message_length);

        Serial.print("Message: ");
        for (int i = 0; i < ostream.bytes_written; i++) {
            Serial.printf("%02X", buffer[i]);
        }
        Serial.println();
    }

    /* DECODING */
    {
        TestMessage out_message = TestMessage_init_zero;

        /* Create a stream that reads from the buffer. */
        pb_istream_t stream = pb_istream_from_buffer(buffer, message_length);

        out_message.test_string.funcs.decode = &decode_string;
        //printf((char*)out_message.test_string.arg);

        /* Now we are ready to decode the message. */
        status = pb_decode(&stream, TestMessage_fields, &out_message);

        if (!status) {
            printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
        }

        Serial.print("Message.test_number: ");
        Serial.println(out_message.test_number);
        Serial.print("Message.test_number2: ");
        Serial.println(out_message.test_number2);
        Serial.print("Message.test_number3: ");
        Serial.println(out_message.test_number3);
    }
}

void loop() {
}