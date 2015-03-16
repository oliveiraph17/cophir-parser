#include <iostream>
#include <string>
#include <fstream>
#include "strtk.hpp"

#define XML_FILES 10000000

using namespace std;

int main() {
    typedef strtk::std_string::tokenizer<>::type tokenizer_type;
    strtk::single_delimiter_predicate<string::value_type> predicate(' ');

    // File xml_files.txt has the following structure:
    //
    // /home/ph/Experimentos/cophir/000281284.xml
    // /home/ph/Experimentos/cophir/000281291.xml
    // /home/ph/Experimentos/cophir/000281297.xml
    // ...
    ifstream xml_files("/home/ph/Experimentos/cophir/files.txt");

    // Each line of file input.txt has the following structure:
    //
    // ID
    // Scalable Color      - 64d
    // Color Structure     - 64d
    // Color Layout        - 12d
    // Edge Histogram      - 80d
    // Homogeneous Texture - 62d
    ofstream input("/home/ph/Experimentos/cophir/input.txt");

    string line;
    size_t pos;

    // For each line of files.txt.
    for (int i = 1; i <= XML_FILES; ++i) {
        // Writes a line to input.txt.

        // ID.
        input << i;
        input << " ";

        getline(xml_files, line);

        // Opens current XML file.
        ifstream xml_file(line.c_str());

        bool found_coeff = false;

        bool found_ydc_coeff = false;
        bool found_cbdc_coeff = false;
        bool found_crdc_coeff = false;
        bool found_yac_coeff5 = false;
        bool found_cbac_coeff2 = false;
        bool found_crac_coeff2 = false;

        bool found_values = false;

        bool found_bin_counts = false;

        bool found_average = false;
        bool found_standard_deviation = false;
        bool found_energy = false;
        bool found_energy_deviation = false;

        while (getline(xml_file, line)) {
            ///////////////////////////////////////////////////////////////////////////////////////
            // Scalable Color.
            ///////////////////////////////////////////////////////////////////////////////////////

            if (!found_coeff) {
                pos = line.find("<Coeff>");

                if (pos != string::npos) {
                    string value = line.substr(7, line.length() - 15);

                    tokenizer_type tokenizer(value,
                                             predicate,
                                             strtk::tokenize_options::compress_delimiters);

                    tokenizer_type::iterator itr = tokenizer.begin();

                    while (itr != tokenizer.end()) {
                        if (itr.as_string() != "") {
                            input << itr;
                            input << " ";
                        }

                        ++itr;
                    }

                    found_coeff = true;

                    continue;
                }
            }

            ///////////////////////////////////////////////////////////////////////////////////////
            // Color Layout.
            ///////////////////////////////////////////////////////////////////////////////////////

            if (!found_ydc_coeff) {
                pos = line.find("<YDCCoeff>");

                if (pos != string::npos) {
                    input << line.substr(10, line.length() - 21);
                    input << " ";

                    found_ydc_coeff = true;

                    continue;
                }
            }

            if (!found_cbdc_coeff) {
                pos = line.find("<CbDCCoeff>");

                if (pos != string::npos) {
                    input << line.substr(11, line.length() - 23);
                    input << " ";

                    found_cbdc_coeff = true;

                    continue;
                }
            }

            if (!found_crdc_coeff) {
                pos = line.find("<CrDCCoeff>");

                if (pos != string::npos) {
                    input << line.substr(11, line.length() - 23);
                    input << " ";

                    found_crdc_coeff = true;

                    continue;
                }
            }

            if (!found_yac_coeff5) {
                pos = line.find("<YACCoeff5>");

                if (pos != string::npos) {
                    string value = line.substr(11, line.length() - 23);

                    tokenizer_type tokenizer(value,
                                             predicate,
                                             strtk::tokenize_options::compress_delimiters);

                    tokenizer_type::iterator itr = tokenizer.begin();

                    while (itr != tokenizer.end()) {
                        if (itr.as_string() != "") {
                            input << itr;
                            input << " ";
                        }

                        ++itr;
                    }

                    found_yac_coeff5 = true;

                    continue;
                }
            }

            if (!found_cbac_coeff2) {
                pos = line.find("<CbACCoeff2>");

                if (pos != string::npos) {
                    string value = line.substr(12, line.length() - 25);

                    tokenizer_type tokenizer(value,
                                             predicate,
                                             strtk::tokenize_options::compress_delimiters);

                    tokenizer_type::iterator itr = tokenizer.begin();

                    while (itr != tokenizer.end()) {
                        if (itr.as_string() != "") {
                            input << itr;
                            input << " ";
                        }

                        ++itr;
                    }

                    found_cbac_coeff2 = true;

                    continue;
                }
            }

            if (!found_crac_coeff2) {
                pos = line.find("<CrACCoeff2>");

                if (pos != string::npos) {
                    string value = line.substr(12, line.length() - 25);

                    tokenizer_type tokenizer(value,
                                             predicate,
                                             strtk::tokenize_options::compress_delimiters);

                    tokenizer_type::iterator itr = tokenizer.begin();

                    while (itr != tokenizer.end()) {
                        if (itr.as_string() != "") {
                            input << itr;
                            input << " ";
                        }

                        ++itr;
                    }

                    found_crac_coeff2 = true;

                    continue;
                }
            }

            ///////////////////////////////////////////////////////////////////////////////////////
            // Color Structure.
            ///////////////////////////////////////////////////////////////////////////////////////

            if (!found_values) {
                pos = line.find("<Values>");

                if (pos != string::npos) {
                    string value = line.substr(8, line.length() - 17);

                    tokenizer_type tokenizer(value,
                                             predicate,
                                             strtk::tokenize_options::compress_delimiters);

                    tokenizer_type::iterator itr = tokenizer.begin();

                    while (itr != tokenizer.end()) {
                        if (itr.as_string() != "") {
                            input << itr;
                            input << " ";
                        }

                        ++itr;
                    }

                    found_values = true;

                    continue;
                }
            }

            ///////////////////////////////////////////////////////////////////////////////////////
            // Edge Histogram.
            ///////////////////////////////////////////////////////////////////////////////////////

            if (!found_bin_counts) {
                pos = line.find("<BinCounts>");

                if (pos != string::npos) {
                    string value = line.substr(11, line.length() - 23);

                    tokenizer_type tokenizer(value,
                                             predicate,
                                             strtk::tokenize_options::compress_delimiters);

                    tokenizer_type::iterator itr = tokenizer.begin();

                    while (itr != tokenizer.end()) {
                        if (itr.as_string() != "") {
                            input << itr;
                            input << " ";
                        }

                        ++itr;
                    }

                    found_bin_counts = true;

                    continue;
                }
            }

            ///////////////////////////////////////////////////////////////////////////////////////
            // Homogeneous Texture.
            ///////////////////////////////////////////////////////////////////////////////////////

            if (!found_average) {
                pos = line.find("<Average>");

                if (pos != string::npos) {
                    input << line.substr(9, line.length() - 19);
                    input << " ";

                    found_average = true;

                    continue;
                }
            }

            if (!found_standard_deviation) {
                pos = line.find("<StandardDeviation>");

                if (pos != string::npos) {
                    input << line.substr(19, line.length() - 39);
                    input << " ";

                    found_standard_deviation = true;

                    continue;
                }
            }

            if (!found_energy) {
                pos = line.find("<Energy>");

                if (pos != string::npos) {
                    string value = line.substr(8, line.length() - 17);

                    tokenizer_type tokenizer(value,
                                             predicate,
                                             strtk::tokenize_options::compress_delimiters);

                    tokenizer_type::iterator itr = tokenizer.begin();

                    while (itr != tokenizer.end()) {
                        if (itr.as_string() != "") {
                            input << itr;
                            input << " ";
                        }

                        ++itr;
                    }

                    found_energy = true;

                    continue;
                }
            }

            if (!found_energy_deviation) {
                pos = line.find("<EnergyDeviation>");

                if (pos != string::npos) {
                    string value = line.substr(17, line.length() - 35);

                    tokenizer_type tokenizer(value,
                                             predicate,
                                             strtk::tokenize_options::compress_delimiters);

                    tokenizer_type::iterator itr = tokenizer.begin();

                    while (itr != tokenizer.end()) {
                        if (itr.as_string() != "") {
                            input << itr;
                            input << " ";
                        }

                        ++itr;
                    }

                    found_energy_deviation = true;

                    continue;
                }
            }
        }

        input << endl;
    }

    input.close();
    xml_files.close();

    return 0;
}
