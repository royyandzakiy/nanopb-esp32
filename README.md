# nanopb on ESP32

This project is meant to demonstrate the usage of the nanopb library in order to de/serialize messages from different types.

## Getting started

- Install PlatformIO extension on VSCode
- clone project `https://github.com/royyandzakiy/nanopb-esp32`
- Build, Upload

## To Generate New Protofiles
For a note, the protofiles are already fully usable, because the .h and .c had already been generated. If you want to want to modify the current .c and .h, or you want to generate your own custom .proto file, you can follow these steps

- pip install protobuf grpcio-tools
- to generate protobuf files:
`python ./.pio/libdeps/esp32doit-devkit-v1/Nanopb/generator/nanopb_generator.py .\src\protofiles\<proto_file_name>.proto`

## References
- https://github.com/nanopb/nanopb