[![CloudCompare Plugin](https://img.shields.io/badge/plugin-CloudCompare-brightgreen.svg)](https://github.com/CloudCompare/CloudCompare)
[![License](https://img.shields.io/badge/License-GPL--2.0+-blue.svg)](https://opensource.org/licenses/GPL-2.0)

# LASIO Plugin

This is a plugin for [CloudCompare](https://github.com/CloudCompare/CloudCompare) to add LAS file 1.3 reading & writing based on [LASzip](https://github.com/LASzip/LASzip) and [libLAS](https://github.com/libLAS/libLAS).

It bascially forks the old LAS file handling before CloudCompare moved to using PDAL and puts it in a plugin.

## Versions
I compile using:
- LASzip master from 23 Feb 2016 ([ff16991b](https://github.com/LASzip/LASzip/commit/ff16991bed6e0606adeedbe72743e17a269ded85)) (later versions have breaking changes)
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
- clone this repository in the `CloudCompare/plugins/private` directory
- rerun CloudCompare's cmake
- turn on `PLUGIN-3rdParty_LAS_IO` in your cmake options
- set the `LIBLAS_*` options to point at your `libLAS` build

Note: If you are building for CloudCompare 2.11.x, use the tagged version at `cloudcompare-2.11.x`

## License

This project as a whole is licensed under the [**GPL-2.0-or-later**](https://opensource.org/licenses/GPL-2.0) license - see the [LICENSE](LICENSE.md) file for details.

Individual source files may contain the following tag instead of the full license text:

	SPDX-License-Identifier: GPL-2.0-or-later

Using SPDX enables machine processing of license information based on the [SPDX License Identifiers](https://spdx.org/ids) and makes it easier for developers to see at a glance which license they are dealing with.
