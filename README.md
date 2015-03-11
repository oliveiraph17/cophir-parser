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

This parser uses a tokenizer available on [C++ String Toolkit (StrTk)][2].  
In order to work properly, this toolkit requires [Boost C++ Libraries][3].  
In Ubuntu, one can install them by downloading libboost-all-dev package via apt-get.

[2]: http://www.partow.net/programming/strtk/index.html
[3]: http://www.boost.org/
