//Copyright 2017 Ryan Wick

//This file is part of LongQC

//LongQC is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//LongQC is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with LongQC.  If not, see <http://www.gnu.org/licenses/>.


#include <iostream>
#include "read.h"
#include "arguments.h"
#include "kmers.h"

#define PROGRAM_VERSION "0.1.0"


int main(int argc, char **argv)
{
    Arguments args(argc, argv);
    if (args.parsing_result == BAD)
        return 1;
    else if (args.parsing_result == HELP)
        return 0;
    else if (args.parsing_result == VERSION) {
        std::cout << "LongQC v" << PROGRAM_VERSION << "\n";
        return 0;
    }

//    // TEMP - check argument parsing
//    std::cerr << "\n\n";
//    std::cerr << "input_reads: " << args.input_reads << std::endl;
//    if (args.min_score_set) { std::cerr << "min_score: " << args.min_score << std::endl; }
//    else { std::cerr << "min_score: not set" << std::endl; }
//    if (args.target_bases_set) { std::cerr << "target_bases: " << args.target_bases << std::endl; }
//    else { std::cerr << "target_bases: not set" << std::endl; }
//    if (args.keep_percent_set) { std::cerr << "keep_percent: " << args.keep_percent << std::endl; }
//    else { std::cerr << "keep_percent: not set" << std::endl; }
//    if (args.assembly_set) { std::cerr << "assembly: " << args.assembly << std::endl; }
//    else { std::cerr << "assembly: not set" << std::endl; }
//    if (args.illumina_reads_set) { std::cerr << "illumina_reads: " << args.illumina_reads << std::endl; }
//    else { std::cerr << "illumina_reads: not set" << std::endl; }
//    if (args.min_length_set) { std::cerr << "min_length: " << args.min_length << std::endl; }
//    else { std::cerr << "min_length: not set" << std::endl; }
//    if (args.min_mean_q_set) { std::cerr << "min_mean_q: " << args.min_mean_q << std::endl; }
//    else { std::cerr << "min_mean_q: not set" << std::endl; }
//    if (args.min_window_q_set) { std::cerr << "min_window_q: " << args.min_window_q << std::endl; }
//    else { std::cerr << "min_window_q: not set" << std::endl; }
//    if (args.length_weight_set) { std::cerr << "length_weight: " << args.length_weight << std::endl; }
//    else { std::cerr << "length_weight: not set" << std::endl; }
//    if (args.mean_q_weight_set) { std::cerr << "mean_q_weight: " << args.mean_q_weight << std::endl; }
//    else { std::cerr << "mean_q_weight: not set" << std::endl; }
//    if (args.window_q_weight_set) { std::cerr << "window_q_weight: " << args.window_q_weight << std::endl; }
//    else { std::cerr << "window_q_weight: not set" << std::endl; }
//    if (args.window_size_set) { std::cerr << "window_size: " << args.window_size << std::endl; }
//    else { std::cerr << "window_size: not set" << std::endl; }
//    std::cerr << "verbose: " << args.verbose << std::endl;




    // Read through references and save 16-mers.
    if (args.assembly_set || args.illumina_reads_set) {
        Kmers kmers;
        if (args.assembly_set)
            kmers.add_assembly_fasta(args.assembly);
        if (args.illumina_reads_set)
            kmers.add_read_fastq(args.illumina_reads);
    }

    // Read through input reads once, storing them as Read objects and calculating their scores.

    // Decide which reads will be outputted:
    //  * total up the bases in the input reads
    //  * cull any reads wil fail to meet a threshold
    //  * sort reads from best to worst
    //  * if the user used --keep_percent:
    //     * loop through reads from best to worst
    //     * when we've exceeded the keep percent, all remaining reads are culled
    //  * if the user used --target_bases:
    //     * loop through reads from best to worst
    //     * when we've exceeded the target bases, all remaining reads are culled

    // Read through input reads again, this time outputting the keepers to stdout and ignoring the failures.
    // If in verbose mode, display a table as we go.


    return 0;
}
