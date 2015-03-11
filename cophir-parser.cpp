#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "strtk.hpp"

#define XML_FILES 1000000

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

        string coeff_value;
        string yac_coeff5_value;
        string cbac_coeff2_value;
        string crac_coeff2_value;
        string values_value;
        string bin_counts_value;
        string energy_value;
        string energy_deviation_value;

        ////////////////////////////////////////////////////////////////////////////////////////
        // Scalable Color.
        ////////////////////////////////////////////////////////////////////////////////////////

        while (getline(xml_file, line)) {
            pos = line.find("<Coeff>");

            if (pos != string::npos) {
                coeff_value = line.substr(7, line.length() - 15);

                break;
            }
        }

        tokenizer_type coeff_tokenizer(coeff_value,
                                       predicate,
                                       strtk::tokenize_options::compress_delimiters);

        tokenizer_type::iterator itr = coeff_tokenizer.begin();

        while (itr != coeff_tokenizer.end()) {
            if (itr.as_string() != "") {
                input << itr;
                input << " ";
            }

            ++itr;
        }

        ////////////////////////////////////////////////////////////////////////////////////////
        // Color Layout.
        ////////////////////////////////////////////////////////////////////////////////////////

        while (getline(xml_file, line)) {
            pos = line.find("<YDCCoeff>");

            if (pos != string::npos) {
                input << line.substr(10, line.length() - 21);
                input << " ";

                break;
            }
        }

        while (getline(xml_file, line)) {
            pos = line.find("<CbDCCoeff>");

            if (pos != string::npos) {
                input << line.substr(11, line.length() - 23);
                input << " ";

                break;
            }
        }

        while (getline(xml_file, line)) {
            pos = line.find("<CrDCCoeff>");

            if (pos != string::npos) {
                input << line.substr(11, line.length() - 23);
                input << " ";

                break;
            }
        }

        while (getline(xml_file, line)) {
            pos = line.find("<YACCoeff5>");

            if (pos != string::npos) {
                yac_coeff5_value = line.substr(11, line.length() - 23);

                break;
            }
        }

        tokenizer_type yac_coeff5_tokenizer(yac_coeff5_value,
                                            predicate,
                                            strtk::tokenize_options::compress_delimiters);

        itr = yac_coeff5_tokenizer.begin();

        while (itr != yac_coeff5_tokenizer.end()) {
            if (itr.as_string() != "") {
                input << itr;
                input << " ";
            }

            ++itr;
        }

        while (getline(xml_file, line)) {
            pos = line.find("<CbACCoeff2>");

            if (pos != string::npos) {
                cbac_coeff2_value = line.substr(12, line.length() - 25);

                break;
            }
        }

        tokenizer_type cbac_coeff2_tokenizer(cbac_coeff2_value,
                                             predicate,
                                             strtk::tokenize_options::compress_delimiters);

        itr = cbac_coeff2_tokenizer.begin();

        while (itr != cbac_coeff2_tokenizer.end()) {
            if (itr.as_string() != "") {
                input << itr;
                input << " ";
            }

            ++itr;
        }

        while (getline(xml_file, line)) {
            pos = line.find("<CrACCoeff2>");

            if (pos != string::npos) {
                crac_coeff2_value = line.substr(12, line.length() - 25);

                break;
            }
        }

        tokenizer_type crac_coeff2_tokenizer(crac_coeff2_value,
                                             predicate,
                                             strtk::tokenize_options::compress_delimiters);

        itr = crac_coeff2_tokenizer.begin();

        while (itr != crac_coeff2_tokenizer.end()) {
            if (itr.as_string() != "") {
                input << itr;
                input << " ";
            }

            ++itr;
        }

        ////////////////////////////////////////////////////////////////////////////////////////
        // Color Structure.
        ////////////////////////////////////////////////////////////////////////////////////////

        while (getline(xml_file, line)) {
            pos = line.find("<Values>");

            if (pos != string::npos) {
                values_value = line.substr(8, line.length() - 17);

                break;
            }
        }

        tokenizer_type values_tokenizer(values_value,
                                        predicate,
                                        strtk::tokenize_options::compress_delimiters);

        itr = values_tokenizer.begin();

        while (itr != values_tokenizer.end()) {
            if (itr.as_string() != "") {
                input << itr;
                input << " ";
            }

            ++itr;
        }

        ////////////////////////////////////////////////////////////////////////////////////////
        // Edge Histogram.
        ////////////////////////////////////////////////////////////////////////////////////////

        while (getline(xml_file, line)) {
            pos = line.find("<BinCounts>");

            if (pos != string::npos) {
                // Retorna a substring com os números, removendo <BinCounts> e </BinCounts>.
                bin_counts_value = line.substr(11, line.length() - 23);

                break;
            }
        }

        tokenizer_type bin_counts_tokenizer(bin_counts_value,
                                            predicate,
                                            strtk::tokenize_options::compress_delimiters);

        itr = bin_counts_tokenizer.begin();

        while (itr != bin_counts_tokenizer.end()) {
            if (itr.as_string() != "") {
                input << itr;
                input << " ";
            }

            ++itr;
        }

        ////////////////////////////////////////////////////////////////////////////////////////
        // Homogeneous Texture.
        ////////////////////////////////////////////////////////////////////////////////////////

        while (getline(xml_file, line)) {
            pos = line.find("<Average>");

            if (pos != string::npos) {
                input << line.substr(9, line.length() - 19);
                input << " ";

                break;
            }
        }

        while (getline(xml_file, line)) {
            pos = line.find("<StandardDeviation>");

            if (pos != string::npos) {
                input << line.substr(19, line.length() - 39);
                input << " ";

                break;
            }
        }

        while (getline(xml_file, line)) {
            pos = line.find("<Energy>");

            if (pos != string::npos) {
                energy_value = line.substr(8, line.length() - 17);

                break;
            }
        }

        tokenizer_type energy_tokenizer(energy_value,
                                        predicate,
                                        strtk::tokenize_options::compress_delimiters);

        itr = energy_tokenizer.begin();

        while (itr != energy_tokenizer.end()) {
            if (itr.as_string() != "") {
                input << itr;
                input << " ";
            }

            ++itr;
        }

        while (getline(xml_file, line)) {
            pos = line.find("<EnergyDeviation>");

            if (pos != string::npos) {
                energy_deviation_value = line.substr(17, line.length() - 35);

                break;
            }
        }

        tokenizer_type energy_deviation_tokenizer(energy_deviation_value,
                                                  predicate,
                                                  strtk::tokenize_options::compress_delimiters);

        itr = energy_deviation_tokenizer.begin();

        while (itr != energy_deviation_tokenizer.end()) {
            if (itr.as_string() != "") {
                input << itr;
                input << " ";
            }

            ++itr;
        }

        input << endl;
    }

    input.close();
    xml_files.close();

    return 0;
}
