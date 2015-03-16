#include <iostream>
#include <string>
#include <fstream>
#include <list>
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
        // Reads current XML file name.
        getline(xml_files, line);

        // Opens current XML file.
        ifstream xml_file(line.c_str());

        // Boolean variables.

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

        // String variables.

        string coeff_value;

        string ydc_coeff_value;
        string cbdc_coeff_value;
        string crdc_coeff_value;
        string yac_coeff5_value;
        string cbac_coeff2_value;
        string crac_coeff2_value;

        string values_value;

        string bin_counts_value;

        string average_value;
        string standard_deviation_value;
        string energy_value;
        string energy_deviation_value;

        // Lists and variables for storing each integer.

        list<int> coeff;

        int ydc_coeff;
        int cbdc_coeff;
        int crdc_coeff;
        list<int> yac_coeff5;
        list<int> cbac_coeff2;
        list<int> crac_coeff2;

        list<int> values;

        list<int> bin_counts;

        int average;
        int standard_deviation;
        list<int> energy;
        list<int> energy_deviation;

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
                            coeff.push_back(atoi(itr.as_string().c_str()));
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
                    ydc_coeff = atoi(line.substr(10, line.length() - 21).c_str());

                    found_ydc_coeff = true;

                    continue;
                }
            }

            if (!found_cbdc_coeff) {
                pos = line.find("<CbDCCoeff>");

                if (pos != string::npos) {
                    cbdc_coeff = atoi(line.substr(11, line.length() - 23).c_str());

                    found_cbdc_coeff = true;

                    continue;
                }
            }

            if (!found_crdc_coeff) {
                pos = line.find("<CrDCCoeff>");

                if (pos != string::npos) {
                    crdc_coeff = atoi(line.substr(11, line.length() - 23).c_str());

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
                            yac_coeff5.push_back(atoi(itr.as_string().c_str()));
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
                            cbac_coeff2.push_back(atoi(itr.as_string().c_str()));
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
                            crac_coeff2.push_back(atoi(itr.as_string().c_str()));
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
                            values.push_back(atoi(itr.as_string().c_str()));
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
                            bin_counts.push_back(atoi(itr.as_string().c_str()));
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
                    average = atoi(line.substr(9, line.length() - 19).c_str());

                    found_average = true;

                    continue;
                }
            }

            if (!found_standard_deviation) {
                pos = line.find("<StandardDeviation>");

                if (pos != string::npos) {
                    standard_deviation = atoi(line.substr(19, line.length() - 39).c_str());

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
                            energy.push_back(atoi(itr.as_string().c_str()));
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
                            energy_deviation.push_back(atoi(itr.as_string().c_str()));
                        }

                        ++itr;
                    }

                    found_energy_deviation = true;

                    continue;
                }
            }
        }

        list<int>::iterator itr;

        // The following instructions write a line to input.txt.

        // ID.

        input << i;
        input << " ";

        // Scalable Color - 64d.

        for (itr = coeff.begin(); itr != coeff.end(); ++itr) {
            input << *itr;
            input << " ";
        }

        // Color Layout - 12d.

        input << ydc_coeff;
        input << " ";

        input << cbdc_coeff;
        input << " ";

        input << crdc_coeff;
        input << " ";

        for (itr = yac_coeff5.begin(); itr != yac_coeff5.end(); ++itr) {
            input << *itr;
            input << " ";
        }

        for (itr = cbac_coeff2.begin(); itr != cbac_coeff2.end(); ++itr) {
            input << *itr;
            input << " ";
        }

        for (itr = crac_coeff2.begin(); itr != crac_coeff2.end(); ++itr) {
            input << *itr;
            input << " ";
        }

        // Color Structure - 64d.

        for (itr = values.begin(); itr != values.end(); ++itr) {
            input << *itr;
            input << " ";
        }

        // Edge Histogram - 80d.

        for (itr = bin_counts.begin(); itr != bin_counts.end(); ++itr) {
            input << *itr;
            input << " ";
        }

        // Homogeneous Texture - 62d.

        input << average;
        input << " ";

        input << standard_deviation;
        input << " ";

        for (itr = energy.begin(); itr != energy.end(); ++itr) {
            input << *itr;
            input << " ";
        }

        for (itr = energy_deviation.begin(); itr != energy_deviation.end(); ++itr) {
            input << *itr;
            input << " ";
        }

        // End of line.

        input << endl;
    }

    input.close();
    xml_files.close();

    return 0;
}
