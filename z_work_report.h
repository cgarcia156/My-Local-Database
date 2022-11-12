#ifndef Z_WORK_REPORT_H_
#define Z_WORK_REPORT_H_

/*
    Features:

        -Implemented: 

            SQL: 
                -Takes input from the command line or from
                a batch file if the user types batch filename.txt

                -Uses Parser to get the commands then calls the proper
                table functions

            Parser:
                -Uses string tokenizer to turn the input into a
                vector of strings

                -Initializes state machine and keywords list

                -Creates a parse tree which is organized into the
                different pieces of info in a command

                -Parse tree is only returned if it does not end in a
                fail state where the command is invalid

            Table:
                -Constructor to create a table, constructor to open an
                existing table, copy constructor(exact copy)

                -Multiple select functions for different cases
                (select ,select_where, select all)

                -Insert into and delete_where (marks deleted records)

                -Added a [] operator to get a vector of strings of
                everything in a column of the table

                -Uses shunting yard and rpn classes to help with 
                conditions

        -Not implemented: 
                -No option to recover deleted records or view them

*/

#endif // Z_WORK_REPORT_H_
