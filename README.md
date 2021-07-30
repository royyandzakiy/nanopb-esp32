# Nanopb esp32

This project is meant to demonstrate the usage of the nanopb library in order to de/serialize messages from different types.

## Getting started

- Install extension Platform IO on VSCode
- clone project `https://github.com/royyandzakiy/nanopb-esp32`
- Build, Upload

## To Generate New Protofiles
For a note, the protofiles are already fully usable, because the .h and .c had already been generated. If you want to want to modify the current .c and .h, or you want to generate your own custom .proto file, you can follow these steps

- download [nanopb](https://jpa.kapsi.fi/nanopb/download/) or from [github/nanopb](https://github.com/nanopb/nanopb), install as Arduino Library
- to generate protobuf files:
`python ~/Arduino/libraries/Nanopb/generator/nanopb_generator.py <project folder>/proto_files/<protofile.proto>`

## References
- https://github.com/nanopb/nanopb