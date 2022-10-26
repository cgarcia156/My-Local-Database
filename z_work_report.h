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

        -Partly implemented: 
                -No option to recover deleted records or view them

    Bugs     : features that are implemented are bug-free*.

    Reflections:

    This was a tough project there are still many ways I could improve the
    database but I had limited time and hope I at least got the requirements
    done. 
    It includes many things we have learned throughout the semester I am glad
    I was able to take a class with Barkeshli I learned a lot and it was fun!

    Video Link:

    https://youtu.be/S2cTakG0kqw


    * may not actually be bug-free
*/

#endif // Z_WORK_REPORT_H_
