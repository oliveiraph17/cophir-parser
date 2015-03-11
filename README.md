cophir-parser
=============

Parser for creating an input file from [CoPhIR test-collection][1] XML files.

[1]: http://cophir.isti.cnr.it/

Each line of the resulting input file contains an ID and the concatenation of 5 MPEG-7 descriptors:

- **Scalable Color:** 64 integers
- **Color Layout:** 12 integers
- **Color Structure:** 64 integers
- **Edge Histogram:** 80 integers
- **Homogeneous Texture:** 62 integers
