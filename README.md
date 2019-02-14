# LASIO Plugin

This is a plugin for [CloudCompare](https://github.com/CloudCompare/CloudCompare) to add LAS file 1.3 reading & writing based on [LASzip](https://github.com/LASzip/LASzip) and [libLAS](https://github.com/libLAS/libLAS).

It bascially forks the old LAS file handling before CloudCompare moved to using PDAL and puts it in a plugin.

## Versions
I compile using:
- [LASzip v2.2.0](https://github.com/LASzip/LASzip/tree/v2.2.0) (later versions have breaking API changes)
- libLAS master from 19 Jan 2019 ([09d45518](https://github.com/libLAS/libLAS/commit/09d45518776489508f34098f1c159f58b856f459)) with one small change in src/CMakeFiles.txt:
```cmake
add_library(las SHARED ${LIBLAS_SOURCES})
add_library(las_c SHARED ${LIBLAS_C_SOURCES})
```
to link statically:
```cmake
add_library(las STATIC ${LIBLAS_SOURCES})
add_library(las_c STATIC ${LIBLAS_C_SOURCES})
```

## Adding To CloudCompare

- clone and build [LASzip](https://github.com/LASzip/LASzip) and [libLAS](https://github.com/libLAS/libLAS)
- clone this repository in the `CloudCompare/plugins/3rdParty` directory
- rerun CloudCompare's cmake
- turn on `PLUGIN_LAS_IO` in your cmake options
- set the `LIBLAS_*` options to point at your `libLAS` build
