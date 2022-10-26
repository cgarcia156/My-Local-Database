#ifndef Z_OUTPUT_H_
#define Z_OUTPUT_H_

/*

Video Link: https://youtu.be/S2cTakG0kqw

********* Output From Batch _!select.txt************

[36] select * from student where fname = "Anna Grace"

student         Records: 1

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Anna Grace      |Del Rio         |CS              |22              |USAF            |



[37] select * from student where fname = "Teresa Mae"

student         Records: 1

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Teresa Mae      |Gowers          |Chemistry       |22              |Verizon         |




//-------- non-existing string ------------------
[38] select * from student where lname = "Does Not Exist"

student         Records: 0

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------




//****************************************************************************
//              RELATIONAL OPERATORS:
//****************************************************************************

//.................
//:Greater Than   :
//.................
[39] select * from student where lname > Yang

student         Records: 1

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Flo             |Yao             |CS              |20              |Google          |



[40] select * from student where major > Math

student         Records: 2

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Greg            |Pearson         |Physics         |20              |Amazon          |
1               |Calvin          |Woo             |Physics         |22              |Uber            |



[41] select * from student where fname > "Sammuel L."

student         Records: 1

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Teresa Mae      |Gowers          |Chemistry       |22              |Verizon         |



[42] select * from employee where salary > 200000

employee        Records: 3

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Van Gogh        |Jim Bob         |Phys Ed         |230000          |2010            |
1               |Van Gogh        |Vincent         |Art             |240000          |2015            |
2               |Van Gogh        |Vincent         |CS              |245000          |2015            |



[43] select * from employee where dep > Chemistry

employee        Records: 9

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Johnson         |Jack            |HR              |150000          |2014            |
1               |Yao             |Jimmy           |Math            |145000          |2014            |
2               |Jackson         |Flo             |Math            |165000          |2017            |
3               |Jackson         |Billy           |Math            |170000          |2017            |
4               |Johnson         |Mary Ann        |Math            |165000          |2014            |
5               |Johnson         |Billy           |Phys Ed         |102000          |2014            |
6               |Van Gogh        |Jim Bob         |Phys Ed         |230000          |2010            |
7               |Blow            |JoAnn           |Physics         |200000          |2016            |
8               |Johnson         |Billy Bob       |Physics         |142000          |2014            |



[44] select * from employee where last > Jackson

employee        Records: 11

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Johnson         |Jack            |HR              |150000          |2014            |
1               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
2               |Johnson         |Mary Ann        |Math            |165000          |2014            |
3               |Johnson         |Billy Bob       |Physics         |142000          |2014            |
4               |Johnson         |Billy           |Phys Ed         |102000          |2014            |
5               |Van Gogh        |Vincent         |Art             |240000          |2015            |
6               |Van Gogh        |Vincent         |CS              |245000          |2015            |
7               |Van Gogh        |Jim Bob         |Phys Ed         |230000          |2010            |
8               |Yang            |Bo              |CS              |160000          |2013            |
9               |Yao             |Jimmy           |Math            |145000          |2014            |
10              |Yao             |Flo             |CS              |147000          |2012            |



[45] select * from employee where first > "Billy Bob"

employee        Records: 13

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Yang            |Bo              |CS              |160000          |2013            |
1               |Jackson         |Bo              |Chemistry       |130000          |2011            |
2               |Yao             |Flo             |CS              |147000          |2012            |
3               |Jackson         |Flo             |Math            |165000          |2017            |
4               |Johnson         |Jack            |HR              |150000          |2014            |
5               |Van Gogh        |Jim Bob         |Phys Ed         |230000          |2010            |
6               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
7               |Yao             |Jimmy           |Math            |145000          |2014            |
8               |Blow            |JoAnn           |Physics         |200000          |2016            |
9               |Blow            |Joe             |CS              |100000          |2018            |
10              |Johnson         |Mary Ann        |Math            |165000          |2014            |
11              |Van Gogh        |Vincent         |Art             |240000          |2015            |
12              |Van Gogh        |Vincent         |CS              |245000          |2015            |





//. . . . . . . . . . . . . (Greater Than: Non-existing) . . . . . . . . . . . . . . . . . . . . . 
[46] select * from student where age > 50

student         Records: 1

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Alex            |Smith           |Gender Studies  |53              |Amazon          |



[47] select * from student where age > 35

student         Records: 2

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Sammuel L.      |Jackson         |CS              |40              |Uber            |
1               |Alex            |Smith           |Gender Studies  |53              |Amazon          |



[48] select * from student where fname > T

student         Records: 1

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Teresa Mae      |Gowers          |Chemistry       |22              |Verizon         |



[49] select * from employee where salary > 130000

employee        Records: 13

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
1               |Johnson         |Billy Bob       |Physics         |142000          |2014            |
2               |Yao             |Jimmy           |Math            |145000          |2014            |
3               |Yao             |Flo             |CS              |147000          |2012            |
4               |Johnson         |Jack            |HR              |150000          |2014            |
5               |Yang            |Bo              |CS              |160000          |2013            |
6               |Jackson         |Flo             |Math            |165000          |2017            |
7               |Johnson         |Mary Ann        |Math            |165000          |2014            |
8               |Jackson         |Billy           |Math            |170000          |2017            |
9               |Blow            |JoAnn           |Physics         |200000          |2016            |
10              |Van Gogh        |Jim Bob         |Phys Ed         |230000          |2010            |
11              |Van Gogh        |Vincent         |Art             |240000          |2015            |
12              |Van Gogh        |Vincent         |CS              |245000          |2015            |



[50] select * from employee where  year > 2009

employee        Records: 16

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Van Gogh        |Jim Bob         |Phys Ed         |230000          |2010            |
1               |Jackson         |Bo              |Chemistry       |130000          |2011            |
2               |Yao             |Flo             |CS              |147000          |2012            |
3               |Yang            |Bo              |CS              |160000          |2013            |
4               |Johnson         |Jack            |HR              |150000          |2014            |
5               |Yao             |Jimmy           |Math            |145000          |2014            |
6               |Johnson         |Mary Ann        |Math            |165000          |2014            |
7               |Johnson         |Billy Bob       |Physics         |142000          |2014            |
8               |Johnson         |Billy           |Phys Ed         |102000          |2014            |
9               |Van Gogh        |Vincent         |Art             |240000          |2015            |
10              |Van Gogh        |Vincent         |CS              |245000          |2015            |
11              |Blow            |JoAnn           |Physics         |200000          |2016            |
12              |Jackson         |Flo             |Math            |165000          |2017            |
13              |Jackson         |Billy           |Math            |170000          |2017            |
14              |Blow            |Joe             |CS              |100000          |2018            |
15              |Johnson         |Jimmy           |Chemistry       |140000          |2018            |




//. . . . . . . . . . . . . (Greater than: last item) . . . . . . . . . . . . . . . . . .
[51] select * from student where age  > 53

student         Records: 0

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------



[52] select * from student where lname > Yao

student         Records: 0

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------



[53] select * from student where fname > "Teresa Mae"

student         Records: 0

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------



[54] select * from employee where last > "Van Gogh"

employee        Records: 3

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Yang            |Bo              |CS              |160000          |2013            |
1               |Yao             |Jimmy           |Math            |145000          |2014            |
2               |Yao             |Flo             |CS              |147000          |2012            |



[55] select * from employee where first > Vincent

employee        Records: 0

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------



[56] select * from employee where salary > 260000

employee        Records: 0

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------




//. . . . . . . . . . . . . (Greater Than: Passed last item) . . . . . . . . . . . . . . . . . . . . . 
[57] select * from student where age > 54

student         Records: 0

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------



[58] select * from student where lname > Zoolander

student         Records: 0

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------



[59] select * from employee where last > Zoolaner

employee        Records: 0

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------



[60] select * from employee where first > Xu

employee        Records: 0

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------




//.................
//:Greater Equal  :
//.................
[61] select * from student where lname >= Yang

student         Records: 2

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Bo              |Yang            |CS              |28              |Microsoft       |
1               |Flo             |Yao             |CS              |20              |Google          |



[62] select * from student where fname >= "Sammuel L."

student         Records: 2

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Sammuel L.      |Jackson         |CS              |40              |Uber            |
1               |Teresa Mae      |Gowers          |Chemistry       |22              |Verizon         |



[63] select * from student where age >= 40

student         Records: 2

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Sammuel L.      |Jackson         |CS              |40              |Uber            |
1               |Alex            |Smith           |Gender Studies  |53              |Amazon          |



//. . . . . .  (Greater Equal non-existing: ) . . . . . . . . . . . 
[64] select * from employee where last >= Jack

employee        Records: 14

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Jackson         |Flo             |Math            |165000          |2017            |
1               |Jackson         |Bo              |Chemistry       |130000          |2011            |
2               |Jackson         |Billy           |Math            |170000          |2017            |
3               |Johnson         |Jack            |HR              |150000          |2014            |
4               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
5               |Johnson         |Mary Ann        |Math            |165000          |2014            |
6               |Johnson         |Billy Bob       |Physics         |142000          |2014            |
7               |Johnson         |Billy           |Phys Ed         |102000          |2014            |
8               |Van Gogh        |Vincent         |Art             |240000          |2015            |
9               |Van Gogh        |Vincent         |CS              |245000          |2015            |
10              |Van Gogh        |Jim Bob         |Phys Ed         |230000          |2010            |
11              |Yang            |Bo              |CS              |160000          |2013            |
12              |Yao             |Jimmy           |Math            |145000          |2014            |
13              |Yao             |Flo             |CS              |147000          |2012            |



[65] select * from employee where first >= Bill

employee        Records: 16

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Jackson         |Billy           |Math            |170000          |2017            |
1               |Johnson         |Billy           |Phys Ed         |102000          |2014            |
2               |Johnson         |Billy Bob       |Physics         |142000          |2014            |
3               |Yang            |Bo              |CS              |160000          |2013            |
4               |Jackson         |Bo              |Chemistry       |130000          |2011            |
5               |Yao             |Flo             |CS              |147000          |2012            |
6               |Jackson         |Flo             |Math            |165000          |2017            |
7               |Johnson         |Jack            |HR              |150000          |2014            |
8               |Van Gogh        |Jim Bob         |Phys Ed         |230000          |2010            |
9               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
10              |Yao             |Jimmy           |Math            |145000          |2014            |
11              |Blow            |JoAnn           |Physics         |200000          |2016            |
12              |Blow            |Joe             |CS              |100000          |2018            |
13              |Johnson         |Mary Ann        |Math            |165000          |2014            |
14              |Van Gogh        |Vincent         |Art             |240000          |2015            |
15              |Van Gogh        |Vincent         |CS              |245000          |2015            |



[66] select * from employee where salary >= 235000

employee        Records: 2

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Van Gogh        |Vincent         |Art             |240000          |2015            |
1               |Van Gogh        |Vincent         |CS              |245000          |2015            |





//.................
//:Less Than      :
//.................


//. . . . . . . . . . . . . (Less Than: Non-existing) . . . . . . . . . . . . . . . . . . . . . 
[67] select * from student where lname < Jackson

student         Records: 2

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Anna Grace      |Del Rio         |CS              |22              |USAF            |
1               |Teresa Mae      |Gowers          |Chemistry       |22              |Verizon         |



[68] select * from student where major < Math

student         Records: 6

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Flo             |Yao             |CS              |20              |Google          |
1               |Bo              |Yang            |CS              |28              |Microsoft       |
2               |Sammuel L.      |Jackson         |CS              |40              |Uber            |
3               |Anna Grace      |Del Rio         |CS              |22              |USAF            |
4               |Teresa Mae      |Gowers          |Chemistry       |22              |Verizon         |
5               |Alex            |Smith           |Gender Studies  |53              |Amazon          |



[69] select * from student where fname < "Jim Bob"

student         Records: 7

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Alex            |Smith           |Gender Studies  |53              |Amazon          |
1               |Anna Grace      |Del Rio         |CS              |22              |USAF            |
2               |Bo              |Yang            |CS              |28              |Microsoft       |
3               |Calvin          |Woo             |Physics         |22              |Uber            |
4               |Flo             |Yao             |CS              |20              |Google          |
5               |Flo             |Jackson         |Math            |21              |Google          |
6               |Greg            |Pearson         |Physics         |20              |Amazon          |



[70] select * from employee where salary < 200000

employee        Records: 12

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Blow            |Joe             |CS              |100000          |2018            |
1               |Johnson         |Billy           |Phys Ed         |102000          |2014            |
2               |Jackson         |Bo              |Chemistry       |130000          |2011            |
3               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
4               |Johnson         |Billy Bob       |Physics         |142000          |2014            |
5               |Yao             |Jimmy           |Math            |145000          |2014            |
6               |Yao             |Flo             |CS              |147000          |2012            |
7               |Johnson         |Jack            |HR              |150000          |2014            |
8               |Yang            |Bo              |CS              |160000          |2013            |
9               |Jackson         |Flo             |Math            |165000          |2017            |
10              |Johnson         |Mary Ann        |Math            |165000          |2014            |
11              |Jackson         |Billy           |Math            |170000          |2017            |



[71] select * from employee where dep < CS

employee        Records: 1

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Van Gogh        |Vincent         |Art             |240000          |2015            |



[72] select * from employee where last < Jackson

employee        Records: 2

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Blow            |Joe             |CS              |100000          |2018            |
1               |Blow            |JoAnn           |Physics         |200000          |2016            |



[73] select * from employee where first < "Billy Bob"

employee        Records: 2

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Jackson         |Billy           |Math            |170000          |2017            |
1               |Johnson         |Billy           |Phys Ed         |102000          |2014            |




//. . . . . . . . . . . . . (Less than: first item) . . . . . . . . . . . . . . . . . .
[74] select * from student where age  < 20

student         Records: 0

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------



[75] select * from student where lname < "Del Rio"

student         Records: 0

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------



[76] select * from student where fname < Alex

student         Records: 0

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------



[77] select * from employee where last < Blow

employee        Records: 0

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------



[78] select * from employee where first < Billy

employee        Records: 0

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------



[79] select * from employee where salary < 100000

employee        Records: 0

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------





//. . . . . . . . . . . . . (Less Than: before first item) . . . . . . . . . . . . . . . . . . . . . 

[80] select * from student where age  < 19

student         Records: 0

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------



[81] select * from student where lname < Adams

student         Records: 0

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------



[82] select * from student where fname < Adam

student         Records: 0

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------



[83] select * from employee where last < Alex

employee        Records: 0

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------



[84] select * from employee where first < Avory

employee        Records: 0

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------



[85] select * from employee where dep < Alchemy

employee        Records: 0

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------





//.................
//:Less Equal     :
//.................

[86] select * from student where lname <= Smith

student         Records: 7

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Anna Grace      |Del Rio         |CS              |22              |USAF            |
1               |Teresa Mae      |Gowers          |Chemistry       |22              |Verizon         |
2               |Sammuel L.      |Jackson         |CS              |40              |Uber            |
3               |Flo             |Jackson         |Math            |21              |Google          |
4               |Greg            |Pearson         |Physics         |20              |Amazon          |
5               |Jim Bob         |Smith           |Math            |23              |Verizon         |
6               |Alex            |Smith           |Gender Studies  |53              |Amazon          |



[87] select * from student where fname <= Greg

student         Records: 7

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Alex            |Smith           |Gender Studies  |53              |Amazon          |
1               |Anna Grace      |Del Rio         |CS              |22              |USAF            |
2               |Bo              |Yang            |CS              |28              |Microsoft       |
3               |Calvin          |Woo             |Physics         |22              |Uber            |
4               |Flo             |Yao             |CS              |20              |Google          |
5               |Flo             |Jackson         |Math            |21              |Google          |
6               |Greg            |Pearson         |Physics         |20              |Amazon          |



[88] select * from student where age <= 40

student         Records: 9

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Flo             |Yao             |CS              |20              |Google          |
1               |Greg            |Pearson         |Physics         |20              |Amazon          |
2               |Flo             |Jackson         |Math            |21              |Google          |
3               |Calvin          |Woo             |Physics         |22              |Uber            |
4               |Anna Grace      |Del Rio         |CS              |22              |USAF            |
5               |Teresa Mae      |Gowers          |Chemistry       |22              |Verizon         |
6               |Jim Bob         |Smith           |Math            |23              |Verizon         |
7               |Bo              |Yang            |CS              |28              |Microsoft       |
8               |Sammuel L.      |Jackson         |CS              |40              |Uber            |




//. . . . . .  (Less Equal non-existing: ) . . . . . . . . . . . 
[89] select * from employee where last <= Peach

employee        Records: 10

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Blow            |Joe             |CS              |100000          |2018            |
1               |Blow            |JoAnn           |Physics         |200000          |2016            |
2               |Jackson         |Flo             |Math            |165000          |2017            |
3               |Jackson         |Bo              |Chemistry       |130000          |2011            |
4               |Jackson         |Billy           |Math            |170000          |2017            |
5               |Johnson         |Jack            |HR              |150000          |2014            |
6               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
7               |Johnson         |Mary Ann        |Math            |165000          |2014            |
8               |Johnson         |Billy Bob       |Physics         |142000          |2014            |
9               |Johnson         |Billy           |Phys Ed         |102000          |2014            |



[90] select * from employee where first <= Gary

employee        Records: 7

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Jackson         |Billy           |Math            |170000          |2017            |
1               |Johnson         |Billy           |Phys Ed         |102000          |2014            |
2               |Johnson         |Billy Bob       |Physics         |142000          |2014            |
3               |Yang            |Bo              |CS              |160000          |2013            |
4               |Jackson         |Bo              |Chemistry       |130000          |2011            |
5               |Yao             |Flo             |CS              |147000          |2012            |
6               |Jackson         |Flo             |Math            |165000          |2017            |



[91] select * from employee where salary <= 23500

employee        Records: 14

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Blow            |Joe             |CS              |100000          |2018            |
1               |Johnson         |Billy           |Phys Ed         |102000          |2014            |
2               |Jackson         |Bo              |Chemistry       |130000          |2011            |
3               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
4               |Johnson         |Billy Bob       |Physics         |142000          |2014            |
5               |Yao             |Jimmy           |Math            |145000          |2014            |
6               |Yao             |Flo             |CS              |147000          |2012            |
7               |Johnson         |Jack            |HR              |150000          |2014            |
8               |Yang            |Bo              |CS              |160000          |2013            |
9               |Jackson         |Flo             |Math            |165000          |2017            |
10              |Johnson         |Mary Ann        |Math            |165000          |2014            |
11              |Jackson         |Billy           |Math            |170000          |2017            |
12              |Blow            |JoAnn           |Physics         |200000          |2016            |
13              |Van Gogh        |Jim Bob         |Phys Ed         |230000          |2010            |




//****************************************************************************
//              LOGICAL OPERATORS
//****************************************************************************


//.................
//:AND            :
//.................

[92] select * from student where fname = "Flo" and lname = "Yao"

student         Records: 1

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Flo             |Yao             |CS              |20              |Google          |



[93] select * from student where major = "CS" and age < 25

student         Records: 2

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Flo             |Yao             |CS              |20              |Google          |
1               |Anna Grace      |Del Rio         |CS              |22              |USAF            |



[94] select * from student where major < Math and age > 25

student         Records: 3

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Bo              |Yang            |CS              |28              |Microsoft       |
1               |Sammuel L.      |Jackson         |CS              |40              |Uber            |
2               |Alex            |Smith           |Gender Studies  |53              |Amazon          |



[95] select * from employee where dep = CS and salary > 150000

employee        Records: 2

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Yang            |Bo              |CS              |160000          |2013            |
1               |Van Gogh        |Vincent         |CS              |245000          |2015            |



[96] select * from employee where last = Jackson and year < 2015

employee        Records: 1

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Jackson         |Bo              |Chemistry       |130000          |2011            |



[97] select * from employee where last = Johnson and year >=2014

employee        Records: 5

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Johnson         |Jack            |HR              |150000          |2014            |
1               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
2               |Johnson         |Mary Ann        |Math            |165000          |2014            |
3               |Johnson         |Billy Bob       |Physics         |142000          |2014            |
4               |Johnson         |Billy           |Phys Ed         |102000          |2014            |





//.................
//:OR            :
//.................
[98] select * from student where fname = Flo or lname = Jackson

student         Records: 3

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Flo             |Yao             |CS              |20              |Google          |
1               |Sammuel L.      |Jackson         |CS              |40              |Uber            |
2               |Flo             |Jackson         |Math            |21              |Google          |



[99] select * from student where age >=40  or company = Verizon

student         Records: 4

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Sammuel L.      |Jackson         |CS              |40              |Uber            |
1               |Jim Bob         |Smith           |Math            |23              |Verizon         |
2               |Teresa Mae      |Gowers          |Chemistry       |22              |Verizon         |
3               |Alex            |Smith           |Gender Studies  |53              |Amazon          |



[100] select * from employee where first = Bo or last = Johnson

employee        Records: 7

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Johnson         |Jack            |HR              |150000          |2014            |
1               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
2               |Yang            |Bo              |CS              |160000          |2013            |
3               |Jackson         |Bo              |Chemistry       |130000          |2011            |
4               |Johnson         |Mary Ann        |Math            |165000          |2014            |
5               |Johnson         |Billy Bob       |Physics         |142000          |2014            |
6               |Johnson         |Billy           |Phys Ed         |102000          |2014            |



[101] select * from employee where year >= 2015 or dep = CS

employee        Records: 9

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Blow            |Joe             |CS              |100000          |2018            |
1               |Blow            |JoAnn           |Physics         |200000          |2016            |
2               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
3               |Yao             |Flo             |CS              |147000          |2012            |
4               |Yang            |Bo              |CS              |160000          |2013            |
5               |Jackson         |Flo             |Math            |165000          |2017            |
6               |Jackson         |Billy           |Math            |170000          |2017            |
7               |Van Gogh        |Vincent         |Art             |240000          |2015            |
8               |Van Gogh        |Vincent         |CS              |245000          |2015            |





//.................
//:OR AND         :
//.................
[102] select * from student where fname = Flo or major = CS and age <= 23

student         Records: 3

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Flo             |Yao             |CS              |20              |Google          |
1               |Flo             |Jackson         |Math            |21              |Google          |
2               |Anna Grace      |Del Rio         |CS              |22              |USAF            |



[103] select * from student where lname = Jackson or age < 23 and company > Uber

student         Records: 3

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Sammuel L.      |Jackson         |CS              |40              |Uber            |
1               |Flo             |Jackson         |Math            |21              |Google          |
2               |Teresa Mae      |Gowers          |Chemistry       |22              |Verizon         |



[104] select * from employee where last = "Van Gogh" or last = Jackson and salary >= 165000

employee        Records: 5

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Jackson         |Flo             |Math            |165000          |2017            |
1               |Jackson         |Billy           |Math            |170000          |2017            |
2               |Van Gogh        |Vincent         |Art             |240000          |2015            |
3               |Van Gogh        |Vincent         |CS              |245000          |2015            |
4               |Van Gogh        |Jim Bob         |Phys Ed         |230000          |2010            |





//.................
//:AND OR AND     :
//.................

[105] select * from student where age <30 and major=CS or major = Physics and company = Amazon

student         Records: 4

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Flo             |Yao             |CS              |20              |Google          |
1               |Bo              |Yang            |CS              |28              |Microsoft       |
2               |Greg            |Pearson         |Physics         |20              |Amazon          |
3               |Anna Grace      |Del Rio         |CS              |22              |USAF            |



[106] select * from student where age <=40 and company=Uber or major = CS and company = Google

student         Records: 3

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Flo             |Yao             |CS              |20              |Google          |
1               |Sammuel L.      |Jackson         |CS              |40              |Uber            |
2               |Calvin          |Woo             |Physics         |22              |Uber            |



[107] select * from employee where dep = CS and salary >= 160000 or year > 2014 and last = "Van Gogh"

employee        Records: 3

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Yang            |Bo              |CS              |160000          |2013            |
1               |Van Gogh        |Vincent         |Art             |240000          |2015            |
2               |Van Gogh        |Vincent         |CS              |245000          |2015            |





//.................
//:OR AND OR      :
//.................

[108] select * from student where lname = Yang or major = CS and age < 23 or company = Google 

student         Records: 4

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Flo             |Yao             |CS              |20              |Google          |
1               |Bo              |Yang            |CS              |28              |Microsoft       |
2               |Flo             |Jackson         |Math            |21              |Google          |
3               |Anna Grace      |Del Rio         |CS              |22              |USAF            |



[109] select * from student where major = Physics or major = Math and company = Google or lname = Jackson

student         Records: 4

Record          |fname           |lname           |major           |age             |company         |
------------------------------------------------------------------------------------------------------
0               |Sammuel L.      |Jackson         |CS              |40              |Uber            |
1               |Flo             |Jackson         |Math            |21              |Google          |
2               |Greg            |Pearson         |Physics         |20              |Amazon          |
3               |Calvin          |Woo             |Physics         |22              |Uber            |



[110] select * from employee where dep = CS or year >2014 and year < 2018 or salary >= 265000

employee        Records: 8

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Blow            |Joe             |CS              |100000          |2018            |
1               |Blow            |JoAnn           |Physics         |200000          |2016            |
2               |Yao             |Flo             |CS              |147000          |2012            |
3               |Yang            |Bo              |CS              |160000          |2013            |
4               |Jackson         |Flo             |Math            |165000          |2017            |
5               |Jackson         |Billy           |Math            |170000          |2017            |
6               |Van Gogh        |Vincent         |Art             |240000          |2015            |
7               |Van Gogh        |Vincent         |CS              |245000          |2015            |





*********** MORE TESTING *************

------ SQL Tables I Manage: --------
Table Names
Uni
employee
student
------------------------------------



Enter an SQL command (create/select/insert/delete/drop)
OR
Batch a file with the command: batch file_name.txt


Enter exit to quit the program


>select * from Uni

Uni             Records: 10

Record          |Rank            |Name            |Tuition         |GradIncome      |
-------------------------------------------------------------------------------------
0               |10              |Cal Poly SLO    |09816           |66900           |
1               |17              |Cal Poly Pomona |07353           |54000           |
2               |09              |UCI             |13700           |58400           |
3               |08              |UCSD            |14167           |59900           |
4               |03              |USC             |56225           |74000           |
5               |05              |UCLA            |13226           |60700           |
6               |04              |UC Berkeley     |14184           |64700           |
7               |12              |UC Davis        |14402           |58200           |
8               |20              |CSU Long Beach  |06798           |48100           |
9               |16              |San Diego State |07488           |51000           |



>select * from Uni where Tuition < 20000

Uni             Records: 9

Record          |Rank            |Name            |Tuition         |GradIncome      |
-------------------------------------------------------------------------------------
0               |20              |CSU Long Beach  |06798           |48100           |
1               |17              |Cal Poly Pomona |07353           |54000           |
2               |16              |San Diego State |07488           |51000           |
3               |10              |Cal Poly SLO    |09816           |66900           |
4               |05              |UCLA            |13226           |60700           |
5               |09              |UCI             |13700           |58400           |
6               |08              |UCSD            |14167           |59900           |
7               |04              |UC Berkeley     |14184           |64700           |
8               |12              |UC Davis        |14402           |58200           |



>select * from Uni where (Rank < 10 or Tuition < 20000) and GradIncome >= 58400

Uni             Records: 6

Record          |Rank            |Name            |Tuition         |GradIncome      |
-------------------------------------------------------------------------------------
0               |10              |Cal Poly SLO    |09816           |66900           |
1               |09              |UCI             |13700           |58400           |
2               |08              |UCSD            |14167           |59900           |
3               |03              |USC             |56225           |74000           |
4               |05              |UCLA            |13226           |60700           |
5               |04              |UC Berkeley     |14184           |64700           |



>select * from employee

employee        Records: 16

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Blow            |Joe             |CS              |100000          |2018            |
1               |Blow            |JoAnn           |Physics         |200000          |2016            |
2               |Johnson         |Jack            |HR              |150000          |2014            |
3               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
4               |Yao             |Jimmy           |Math            |145000          |2014            |
5               |Yao             |Flo             |CS              |147000          |2012            |
6               |Yang            |Bo              |CS              |160000          |2013            |
7               |Jackson         |Flo             |Math            |165000          |2017            |
8               |Jackson         |Bo              |Chemistry       |130000          |2011            |
9               |Jackson         |Billy           |Math            |170000          |2017            |
10              |Johnson         |Mary Ann        |Math            |165000          |2014            |
11              |Johnson         |Billy Bob       |Physics         |142000          |2014            |
12              |Johnson         |Billy           |Phys Ed         |102000          |2014            |
13              |Van Gogh        |Vincent         |Art             |240000          |2015            |
14              |Van Gogh        |Vincent         |CS              |245000          |2015            |
15              |Van Gogh        |Jim Bob         |Phys Ed         |230000          |2010            |



>delete from employee where first = Jimmy and dep = Math
SQL::Deletion Complete

>select * from employee

employee        Records: 15

Record          |last            |first           |dep             |salary          |year            |
------------------------------------------------------------------------------------------------------
0               |Blow            |Joe             |CS              |100000          |2018            |
1               |Blow            |JoAnn           |Physics         |200000          |2016            |
2               |Johnson         |Jack            |HR              |150000          |2014            |
3               |Johnson         |Jimmy           |Chemistry       |140000          |2018            |
4               |Yao             |Flo             |CS              |147000          |2012            |
5               |Yang            |Bo              |CS              |160000          |2013            |
6               |Jackson         |Flo             |Math            |165000          |2017            |
7               |Jackson         |Bo              |Chemistry       |130000          |2011            |
8               |Jackson         |Billy           |Math            |170000          |2017            |
9               |Johnson         |Mary Ann        |Math            |165000          |2014            |
10              |Johnson         |Billy Bob       |Physics         |142000          |2014            |
11              |Johnson         |Billy           |Phys Ed         |102000          |2014            |
12              |Van Gogh        |Vincent         |Art             |240000          |2015            |
13              |Van Gogh        |Vincent         |CS              |245000          |2015            |
14              |Van Gogh        |Jim Bob         |Phys Ed         |230000          |2010            |



>select first,last,dep from employee where salary > 120000 and year = 2015

employee        Records: 2

Record          |first           |last            |dep             |
--------------------------------------------------------------------
0               |Vincent         |Van Gogh        |Art             |
1               |Vincent         |Van Gogh        |CS              |



>drop table employee
Table [employee] has been deleted

>select * from employee


Table Not Found

>exit

----------------End---------------

******Output of B+Tree Removal Test*********

NOTE: FULL OUTPUT DID NOT FIT IN MY TERMINAL
      THIS IS THE PART THAT DID FIT

Removing:166

                190
            190
                178
        178
                173
            173
                168
    168
                165
            165
                157
        157
                155
            155
                148
148
                128
            128
                120
            120
                108
        108
                102
            102
                99
        99
                94
            94
                84
            84
                83
    83
                77
            77
                73
            73
                52
        52
                49
            49
                43
43
                36
            36
                32
        32
                17
            17
                15
    15
                9
            9
                7
        7
                6
            6
                1


Removing:157

                190
            190
                178
        178
                173
            173
                168
        168
                165
            165
                155
            155
                148
    148
                128
            128
                120
            120
                108
        108
                102
            102
                99
        99
                94
            94
                84
            84
                83
    83
                77
            77
                73
            73
                52
        52
                49
            49
                43
43
                36
            36
                32
        32
                17
            17
                15
    15
                9
            9
                7
        7
                6
            6
                1


Removing:17

                190
            190
                178
        178
                173
            173
                168
        168
                165
            165
                155
            155
                148
    148
                128
            128
                120
            120
                108
        108
                102
            102
                99
        99
                94
            94
                84
            84
                83
83
                77
            77
                73
            73
                52
        52
                49
            49
                43
    43
                36
            36
                32
            32
                15
        15
                9
            9
                7
        7
                6
            6
                1


Removing:83

                190
            190
                178
        178
                173
            173
                168
        168
                165
            165
                155
            155
                148
    148
                128
            128
                120
            120
                108
        108
                102
            102
                99
        99
                94
            94
                84
84
                77
            77
                73
            73
                52
        52
                49
            49
                43
    43
                36
            36
                32
            32
                15
        15
                9
            9
                7
        7
                6
            6
                1


Removing:43

                190
            190
                178
        178
                173
            173
                168
        168
                165
            165
                155
            155
                148
    148
                128
            128
                120
            120
                108
        108
                102
            102
                99
        99
                94
            94
                84
84
                77
            77
                73
        73
                52
            52
                49
    49
                36
            36
                32
            32
                15
        15
                9
            9
                7
        7
                6
            6
                1


Removing:9

                190
            190
                178
        178
                173
            173
                168
        168
                165
            165
                155
            155
                148
    148
                128
            128
                120
            120
                108
        108
                102
            102
                99
        99
                94
            94
                84
84
                77
            77
                73
        73
                52
            52
                49
    49
                36
            36
                32
        32
                15
            15
                7
        7
                6
            6
                1


Removing:15

                190
            190
                178
        178
                173
            173
                168
        168
                165
            165
                155
            155
                148
    148
                128
            128
                120
            120
                108
        108
                102
            102
                99
        99
                94
            94
                84
84
                77
            77
                73
        73
                52
            52
                49
    49
                36
            36
                32
        32
                7
            7
                6
            6
                1


Removing:36

                190
            190
                178
        178
                173
            173
                168
        168
                165
            165
                155
            155
                148
    148
                128
            128
                120
            120
                108
        108
                102
            102
                99
        99
                94
            94
                84
84
                77
            77
                73
        73
                52
            52
                49
    49
                32
            32
                7
        7
                6
            6
                1


Removing:52

            190
        190
            178
    178
            173
        173
            168
    168
            165
        165
            155
        155
            148
148
            128
        128
            120
        120
            108
    108
            102
        102
            99
    99
            94
        94
            84
84
            77
        77
            73
        73
            49
    49
            32
        32
            7
    7
            6
        6
            1


Removing:148

            190
        190
            178
    178
            173
        173
            168
    168
            165
        165
            155
155
            128
        128
            120
        120
            108
    108
            102
        102
            99
    99
            94
        94
            84
84
            77
        77
            73
        73
            49
    49
            32
        32
            7
    7
            6
        6
            1


Removing:94

            190
        190
            178
    178
            173
        173
            168
    168
            165
        165
            155
155
            128
        128
            120
        120
            108
    108
            102
        102
            99
        99
            84
84
            77
        77
            73
        73
            49
    49
            32
        32
            7
    7
            6
        6
            1


Removing:120

            190
        190
            178
    178
            173
        173
            168
    168
            165
        165
            155
155
            128
        128
            108
    108
            102
        102
            99
        99
            84
84
            77
        77
            73
        73
            49
    49
            32
        32
            7
    7
            6
        6
            1


Removing:77

            190
        190
            178
    178
            173
        173
            168
    168
            165
        165
            155
155
            128
        128
            108
    108
            102
        102
            99
        99
            84
84
            73
        73
            49
    49
            32
        32
            7
    7
            6
        6
            1


Removing:190

            178
        178
            173
        173
            168
    168
            165
        165
            155
155
            128
        128
            108
    108
            102
        102
            99
        99
            84
84
            73
        73
            49
    49
            32
        32
            7
    7
            6
        6
            1


Removing:6

            178
        178
            173
        173
            168
    168
            165
        165
            155
155
            128
        128
            108
    108
            102
        102
            99
        99
            84
84
            73
        73
            49
    49
            32
        32
            7
        7
            1


Removing:128

            178
        178
            173
        173
            168
    168
            165
        165
            155
155
            108
        108
            102
    102
            99
        99
            84
84
            73
        73
            49
    49
            32
        32
            7
        7
            1


Removing:49

            178
        178
            173
        173
            168
    168
            165
        165
            155
155
            108
        108
            102
    102
            99
        99
            84
84
            73
        73
            32
    32
            7
        7
            1


Removing:173

            178
        178
            168
    168
            165
        165
            155
155
            108
        108
            102
    102
            99
        99
            84
84
            73
        73
            32
    32
            7
        7
            1


Removing:155

            178
        178
            168
        168
            165
    165
            108
        108
            102
    102
            99
        99
            84
84
            73
        73
            32
    32
            7
        7
            1


Removing:84

            178
        178
            168
        168
            165
    165
            108
        108
            102
        102
            99
99
            73
        73
            32
    32
            7
        7
            1


Removing:32

        178
    178
        168
    168
        165
165
        108
    108
        102
    102
        99
99
        73
    73
        7
    7
        1


Removing:165

        178
    178
        168
168
        108
    108
        102
    102
        99
99
        73
    73
        7
    7
        1


Removing:99

        178
    178
        168
168
        108
    108
        102
102
        73
    73
        7
    7
        1


Removing:73

        178
    178
        168
168
        108
    108
        102
102
        7
    7
        1


Removing:1

        178
    178
        168
168
        108
    108
        102
    102
        7


Removing:168

        178
    178
        108
108
        102
    102
        7


Removing:108

    178
178
    102
102
    7


Removing:7

    178
178
    102


Removing:178

102


Removing:102



Tests have been successful!


----------------END TEST---------------





*********MASS INSERTION AND REMOVAL TEST FOR B+TREE***********

--------------------------------------------------
         MASS INSERTION AND DELETION TEST
--------------------------------------------------

Making a new tree of size: 500

Removing 500 elements one by one

Size: 499

Size: 498

Size: 497

Size: 496

Size: 495

Size: 494

Size: 493

Size: 492

Size: 491

Size: 490

Size: 489

Size: 488

Size: 487

Size: 486

Size: 485

Size: 484

Size: 483

Size: 482

Size: 481

Size: 480

Size: 479

Size: 478

Size: 477

Size: 476

Size: 475

Size: 474

Size: 473

Size: 472

Size: 471

Size: 470

Size: 469

Size: 468

Size: 467

Size: 466

Size: 465

Size: 464

Size: 463

Size: 462

Size: 461

Size: 460

Size: 459

Size: 458

Size: 457

Size: 456

Size: 455

Size: 454

Size: 453

Size: 452

Size: 451

Size: 450

Size: 449

Size: 448

Size: 447

Size: 446

Size: 445

Size: 444

Size: 443

Size: 442

Size: 441

Size: 440

Size: 439

Size: 438

Size: 437

Size: 436

Size: 435

Size: 434

Size: 433

Size: 432

Size: 431

Size: 430

Size: 429

Size: 428

Size: 427

Size: 426

Size: 425

Size: 424

Size: 423

Size: 422

Size: 421

Size: 420

Size: 419

Size: 418

Size: 417

Size: 416

Size: 415

Size: 414

Size: 413

Size: 412

Size: 411

Size: 410

Size: 409

Size: 408

Size: 407

Size: 406

Size: 405

Size: 404

Size: 403

Size: 402

Size: 401

Size: 400

Size: 399

Size: 398

Size: 397

Size: 396

Size: 395

Size: 394

Size: 393

Size: 392

Size: 391

Size: 390

Size: 389

Size: 388

Size: 387

Size: 386

Size: 385

Size: 384

Size: 383

Size: 382

Size: 381

Size: 380

Size: 379

Size: 378

Size: 377

Size: 376

Size: 375

Size: 374

Size: 373

Size: 372

Size: 371

Size: 370

Size: 369

Size: 368

Size: 367

Size: 366

Size: 365

Size: 364

Size: 363

Size: 362

Size: 361

Size: 360

Size: 359

Size: 358

Size: 357

Size: 356

Size: 355

Size: 354

Size: 353

Size: 352

Size: 351

Size: 350

Size: 349

Size: 348

Size: 347

Size: 346

Size: 345

Size: 344

Size: 343

Size: 342

Size: 341

Size: 340

Size: 339

Size: 338

Size: 337

Size: 336

Size: 335

Size: 334

Size: 333

Size: 332

Size: 331

Size: 330

Size: 329

Size: 328

Size: 327

Size: 326

Size: 325

Size: 324

Size: 323

Size: 322

Size: 321

Size: 320

Size: 319

Size: 318

Size: 317

Size: 316

Size: 315

Size: 314

Size: 313

Size: 312

Size: 311

Size: 310

Size: 309

Size: 308

Size: 307

Size: 306

Size: 305

Size: 304

Size: 303

Size: 302

Size: 301

Size: 300

Size: 299

Size: 298

Size: 297

Size: 296

Size: 295

Size: 294

Size: 293

Size: 292

Size: 291

Size: 290

Size: 289

Size: 288

Size: 287

Size: 286

Size: 285

Size: 284

Size: 283

Size: 282

Size: 281

Size: 280

Size: 279

Size: 278

Size: 277

Size: 276

Size: 275

Size: 274

Size: 273

Size: 272

Size: 271

Size: 270

Size: 269

Size: 268

Size: 267

Size: 266

Size: 265

Size: 264

Size: 263

Size: 262

Size: 261

Size: 260

Size: 259

Size: 258

Size: 257

Size: 256

Size: 255

Size: 254

Size: 253

Size: 252

Size: 251

Size: 250

Size: 249

Size: 248

Size: 247

Size: 246

Size: 245

Size: 244

Size: 243

Size: 242

Size: 241

Size: 240

Size: 239

Size: 238

Size: 237

Size: 236

Size: 235

Size: 234

Size: 233

Size: 232

Size: 231

Size: 230

Size: 229

Size: 228

Size: 227

Size: 226

Size: 225

Size: 224

Size: 223

Size: 222

Size: 221

Size: 220

Size: 219

Size: 218

Size: 217

Size: 216

Size: 215

Size: 214

Size: 213

Size: 212

Size: 211

Size: 210

Size: 209

Size: 208

Size: 207

Size: 206

Size: 205

Size: 204

Size: 203

Size: 202

Size: 201

Size: 200

Size: 199

Size: 198

Size: 197

Size: 196

Size: 195

Size: 194

Size: 193

Size: 192

Size: 191

Size: 190

Size: 189

Size: 188

Size: 187

Size: 186

Size: 185

Size: 184

Size: 183

Size: 182

Size: 181

Size: 180

Size: 179

Size: 178

Size: 177

Size: 176

Size: 175

Size: 174

Size: 173

Size: 172

Size: 171

Size: 170

Size: 169

Size: 168

Size: 167

Size: 166

Size: 165

Size: 164

Size: 163

Size: 162

Size: 161

Size: 160

Size: 159

Size: 158

Size: 157

Size: 156

Size: 155

Size: 154

Size: 153

Size: 152

Size: 151

Size: 150

Size: 149

Size: 148

Size: 147

Size: 146

Size: 145

Size: 144

Size: 143

Size: 142

Size: 141

Size: 140

Size: 139

Size: 138

Size: 137

Size: 136

Size: 135

Size: 134

Size: 133

Size: 132

Size: 131

Size: 130

Size: 129

Size: 128

Size: 127

Size: 126

Size: 125

Size: 124

Size: 123

Size: 122

Size: 121

Size: 120

Size: 119

Size: 118

Size: 117

Size: 116

Size: 115

Size: 114

Size: 113

Size: 112

Size: 111

Size: 110

Size: 109

Size: 108

Size: 107

Size: 106

Size: 105

Size: 104

Size: 103

Size: 102

Size: 101

Size: 100

Size: 99

Size: 98

Size: 97

Size: 96

Size: 95

Size: 94

Size: 93

Size: 92

Size: 91

Size: 90

Size: 89

Size: 88

Size: 87

Size: 86

Size: 85

Size: 84

Size: 83

Size: 82

Size: 81

Size: 80

Size: 79

Size: 78

Size: 77

Size: 76

Size: 75

Size: 74

Size: 73

Size: 72

Size: 71

Size: 70

Size: 69

Size: 68

Size: 67

Size: 66

Size: 65

Size: 64

Size: 63

Size: 62

Size: 61

Size: 60

Size: 59

Size: 58

Size: 57

Size: 56

Size: 55

Size: 54

Size: 53

Size: 52

Size: 51

Size: 50

Size: 49

Size: 48

Size: 47

Size: 46

Size: 45

Size: 44

Size: 43

Size: 42

Size: 41

Size: 40

Size: 39

Size: 38

Size: 37

Size: 36

Size: 35

Size: 34

Size: 33

Size: 32

Size: 31

Size: 30

Size: 29

Size: 28

Size: 27

Size: 26

Size: 25

Size: 24

Size: 23

Size: 22

Size: 21

Size: 20

Size: 19

Size: 18

Size: 17

Size: 16

Size: 15

Size: 14

Size: 13

Size: 12

Size: 11

Size: 10

Size: 9

Size: 8

Size: 7

Size: 6

Size: 5

Size: 4

Size: 3

Size: 2

Size: 1

Size: 0

Tests have been successful!


----------------END TEST---------------


**********EVEN MORE TESTSSS!!!!************

---------------------------------------------
        I N S E R T I O N  T E S T
---------------------------------------------

Inserting 59

59

Inserting 41

59
41

Inserting 5

    59
    41
41
    5

Inserting 55

    59
    55
55
    41
41
    5

Inserting 9

    59
    55
55
    41
41
    9
    5

Inserting 42

    59
    55
55
    42
    41
41
    9
    5

Inserting 95

        95
        59
    59
        55
55
        42
        41
    41
        9
        5

Inserting 2

        95
        59
    59
        55
55
        42
        41
    41
        9
        5
    5
        2

Inserting 63

        95
        63
    63
        59
    59
        55
55
        42
        41
    41
        9
        5
    5
        2

Inserting 62

        95
        63
    63
        62
        59
    59
        55
55
        42
        41
    41
        9
        5
    5
        2

Inserting 99

        99
        95
    95
        63
63
        62
        59
    59
        55
55
        42
        41
    41
        9
        5
    5
        2

Inserting 37

            99
            95
        95
            63
    63
            62
            59
        59
            55
55
            42
            41
        41
            37
            9
    9
            5
        5
            2

Inserting 77

            99
            95
        95
            77
            63
    63
            62
            59
        59
            55
55
            42
            41
        41
            37
            9
    9
            5
        5
            2

Inserting 49

            99
            95
        95
            77
            63
    63
            62
            59
        59
            55
55
            49
            42
        42
            41
        41
            37
            9
    9
            5
        5
            2

Inserting 2

            99
            95
        95
            77
            63
    63
            62
            59
        59
            55
55
            49
            42
        42
            41
        41
            37
            9
    9
            5
        5
            2



----------------END TEST---------------

---------------------------------------------
        I T E R A T O R  T E S T
---------------------------------------------

Tree: 

        panda
        monkey
    monkey
        horse
        goat
goat
        dog
    dog
        cat
        bird


VALID

Iterator: bird

Iterator++

Iterator: cat

Iterator++

Iterator: dog

Iterator++

Iterator: goat

Iterator++

Iterator: horse

Iterator++

Iterator: monkey

Iterator++

Iterator: panda

Iterator++



----------------END TEST---------------

------------------------------------------
        C O P Y/C L E A R  T E S T
------------------------------------------

INITIAL TREE:

        94
        92
    92
        66
        48
    48
        47
47
        36
        35
    35
        31
    31
        30
        20


VALID

SECOND TREE (COPY CONSTRUCTOR):

        94
        92
    92
        66
        48
    48
        47
47
        36
        35
    35
        31
    31
        30
        20


VALID

CHANGING FIRST TREE

FIRST TREE:

            94
            92
        92
            66
            51
    51
            48
        48
            47
47
            41
            36
        36
            35
    35
            31
        31
            30
            20


VALID

SECOND TREE:

        94
        92
    92
        66
        48
    48
        47
47
        36
        35
    35
        31
    31
        30
        20


VALID

CLEARING SECOND TREE:

FIRST TREE:

            94
            92
        92
            66
            51
    51
            48
        48
            47
47
            41
            36
        36
            35
    35
            31
        31
            30
            20


VALID

SECOND TREE:



VALID

FIRST TREE IS NOT EMPTY

SECOND TREE IS EMPTY


SETTING SECOND TREE = FIRST TREE

FIRST TREE:

            94
            92
        92
            66
            51
    51
            48
        48
            47
47
            41
            36
        36
            35
    35
            31
        31
            30
            20


VALID

SECOND TREE:

            94
            92
        92
            66
            51
    51
            48
        48
            47
47
            41
            36
        36
            35
    35
            31
        31
            30
            20


VALID

CLEARING FIRST TREE:

FIRST TREE:



VALID

SECOND TREE:

            94
            92
        92
            66
            51
    51
            48
        48
            47
47
            41
            36
        36
            35
    35
            31
        31
            30
            20


VALID

FIRST TREE IS EMPTY

SECOND TREE IS NOT EMPTY



----------------END TEST---------------

--------------------------------------------------
        C O N T A I N S / G E T  T E S T
--------------------------------------------------

Tree:

                        99
                        98
                    98
                        97
                    97
                        96
                96
                        95
                    95
                        94
                94
                        93
                    93
                        92
            92
                        91
                    91
                        90
                90
                        89
                    89
                        88
        88
                        87
                    87
                        86
                86
                        85
                    85
                        84
            84
                        83
                    83
                        82
                82
                        81
                    81
                        80
    80
                        79
                    79
                        78
                78
                        77
                    77
                        76
            76
                        75
                    75
                        74
                74
                        73
                    73
                        72
        72
                        71
                    71
                        70
                70
                        69
                    69
                        68
            68
                        67
                    67
                        66
                66
                        65
                    65
                        64
64
                        63
                    63
                        62
                62
                        61
                    61
                        60
            60
                        59
                    59
                        58
                58
                        57
                    57
                        56
        56
                        55
                    55
                        54
                54
                        53
                    53
                        52
            52
                        51
                    51
                        50
                50
                        49
                    49
                        48
    48
                        47
                    47
                        46
                46
                        45
                    45
                        44
            44
                        43
                    43
                        42
                42
                        41
                    41
                        40
        40
                        39
                    39
                        38
                38
                        37
                    37
                        36
            36
                        35
                    35
                        34
                34
                        33
                    33
                        32
32
                        31
                    31
                        30
                30
                        29
                    29
                        28
            28
                        27
                    27
                        26
                26
                        25
                    25
                        24
        24
                        23
                    23
                        22
                22
                        21
                    21
                        20
            20
                        19
                    19
                        18
                18
                        17
                    17
                        16
    16
                        15
                    15
                        14
                14
                        13
                    13
                        12
            12
                        11
                    11
                        10
                10
                        9
                    9
                        8
        8
                        7
                    7
                        6
                6
                        5
                    5
                        4
            4
                        3
                    3
                        2
                2
                        1
                    1
                        0


VERIFIED

Getting all values in the tree

0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
SIZE : 100

Using get() on values 100-199

100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
SIZE : 200

--Trying to insert 100 duplicates--

SIZE : 200



----------------END TEST---------------

------------------------------------------------------
        I T E R A T O R  S E A R C H  T E S T
------------------------------------------------------

Tree:

                    100
                    98
                98
                    96
            96
                    94
                94
                    92
            92
                    90
                90
                    88
        88
                    86
                86
                    84
            84
                    82
                82
                    80
    80
                    78
                78
                    76
            76
                    74
                74
                    72
        72
                    70
                70
                    68
            68
                    66
                66
                    64
64
                    62
                62
                    60
            60
                    58
                58
                    56
        56
                    54
                54
                    52
            52
                    50
                50
                    48
    48
                    46
                46
                    44
            44
                    42
                42
                    40
        40
                    38
                38
                    36
            36
                    34
                34
                    32
32
                    30
                30
                    28
            28
                    26
                26
                    24
        24
                    22
                22
                    20
            20
                    18
                18
                    16
    16
                    14
                14
                    12
            12
                    10
                10
                    8
        8
                    6
                6
                    4
            4
                    2
                2
                    0


--Looking for 42--

FOUND : [42]

Testing the iterator:

iterator++
44
iterator++
46
iterator++
48

--Looking for 87--

NOT FOUND

--Looking for 96--

FOUND : [96]

Testing the iterator:

iterator++
98
iterator++
100
iterator++
NULL


New Tree For Bound Tests:

                29
                28
            28
                27
            27
                26
        26
                25
            25
                24
    24
                23
            23
                22
        22
                21
            21
                20
    20
                19
            19
                18
        18
                17
            17
                16
16
                15
            15
                14
        14
                13
            13
                12
    12
                11
            11
                10
        10
                9
            9
                8
8
                7
            7
                6
        6
                5
            5
                4
    4
                3
            3
                2
        2
                1
            1
                0


lower_bound(1) : 1
iterator++
2
iterator++
3
iterator++
4

lower_bound(29) : 29

lower_bound(13) : 13
iterator++
14
iterator++
15
iterator++
16

upper_bound(5) : 6
iterator++
7
iterator++
8
iterator++
9

upper_bound(24) : 25
iterator++
26
iterator++
27
iterator++
28

upper_bound(13) : 14
iterator++
15
iterator++
16
iterator++
17



----------------END TEST---------------


---------------------------------------------
         R E M O V A L  T E S T  1
---------------------------------------------

Initial Tree:

            14
            13
        13
            12
    12
            11
        11
            10
    10
            9
        9
            8
8
            7
        7
            6
    6
            5
        5
            4
4
            3
        3
            2
    2
            1
        1
            0


VALID

Size: 15

--Removing 0--

            14
            13
        13
            12
    12
            11
        11
            10
    10
            9
        9
            8
8
            7
        7
            6
    6
            5
        5
            4
    4
            3
        3
            2
        2
            1


VALID

Size: 14

--Removing 1--

            14
            13
        13
            12
    12
            11
        11
            10
    10
            9
        9
            8
8
            7
        7
            6
    6
            5
        5
            4
    4
            3
        3
            2


VALID

Size: 13

--Removing 2--

            14
            13
        13
            12
    12
            11
        11
            10
    10
            9
        9
            8
8
            7
        7
            6
    6
            5
        5
            4
        4
            3


VALID

Size: 12

--Removing 3--

            14
            13
        13
            12
    12
            11
        11
            10
    10
            9
        9
            8
8
            7
        7
            6
    6
            5
        5
            4


VALID

Size: 11

--Removing 4--

            14
            13
        13
            12
    12
            11
        11
            10
10
            9
        9
            8
    8
            7
        7
            6
        6
            5


VALID

Size: 10

--Removing 5--

            14
            13
        13
            12
    12
            11
        11
            10
10
            9
        9
            8
    8
            7
        7
            6


VALID

Size: 9

--Removing 6--

        14
        13
    13
        12
12
        11
    11
        10
10
        9
    9
        8
    8
        7


VALID

Size: 8

--Removing 7--

        14
        13
    13
        12
12
        11
    11
        10
10
        9
    9
        8


VALID

Size: 7

--Removing 8--

        14
        13
    13
        12
12
        11
    11
        10
    10
        9


VALID

Size: 6

--Removing 9--

        14
        13
    13
        12
12
        11
    11
        10


VALID

Size: 5

--Removing 10--

    14
    13
13
    12
12
    11


VALID

Size: 4

--Removing 11--

    14
    13
13
    12


VALID

Size: 3

--Removing 12--

    14
14
    13


VALID

Size: 2

--Removing 13--

14


VALID

Size: 1

--Removing 14--



VALID

Size: 0



----------------END TEST---------------


---------------------------------------------
         R E M O V A L  T E S T  2
---------------------------------------------

Making a new tree of size: 25

                24
                23
            23
                22
        22
                21
            21
                20
    20
                19
                18
            18
                17
            17
                16
                15
        15
                14
            14
                13
                12
12
                11
                10
            10
                9
                8
        8
                7
            7
                6
                5
            5
                4
    4
                3
            3
                2
        2
                1
            1
                0


--Removing 15

                24
                23
            23
                22
        22
                21
            21
                20
    20
                19
                18
            18
                17
            17
                16
        16
                14
            14
                13
                12
12
                11
                10
            10
                9
                8
        8
                7
            7
                6
                5
            5
                4
    4
                3
            3
                2
        2
                1
            1
                0


VALID

Size: 24

--Removing 20

            24
            23
        23
            22
        22
            21
    21
            19
            18
        18
            17
        17
            16
    16
            14
        14
            13
            12
12
            11
            10
        10
            9
            8
    8
            7
        7
            6
            5
        5
            4
4
            3
        3
            2
    2
            1
        1
            0


VALID

Size: 23

--Removing 5

            24
            23
        23
            22
        22
            21
    21
            19
            18
        18
            17
        17
            16
    16
            14
        14
            13
            12
12
            11
            10
        10
            9
            8
    8
            7
        7
            6
        6
            4
4
            3
        3
            2
    2
            1
        1
            0


VALID

Size: 22

--Removing 7

            24
            23
        23
            22
        22
            21
    21
            19
            18
        18
            17
        17
            16
    16
            14
        14
            13
            12
12
            11
            10
        10
            9
            8
    8
            6
        6
            4
4
            3
        3
            2
    2
            1
        1
            0


VALID

Size: 21

--Removing 19

            24
            23
        23
            22
        22
            21
    21
            18
        18
            17
        17
            16
    16
            14
        14
            13
            12
12
            11
            10
        10
            9
            8
    8
            6
        6
            4
4
            3
        3
            2
    2
            1
        1
            0


VALID

Size: 20

--Removing 10

            24
            23
        23
            22
        22
            21
    21
            18
        18
            17
        17
            16
    16
            14
        14
            13
            12
12
            11
        11
            9
            8
    8
            6
        6
            4
4
            3
        3
            2
    2
            1
        1
            0


VALID

Size: 19

--Removing 9

            24
            23
        23
            22
        22
            21
    21
            18
        18
            17
        17
            16
    16
            14
        14
            13
            12
12
            11
        11
            8
    8
            6
        6
            4
4
            3
        3
            2
    2
            1
        1
            0


VALID

Size: 18

--Removing 8

            24
            23
        23
            22
        22
            21
    21
            18
        18
            17
        17
            16
16
            14
        14
            13
            12
    12
            11
        11
            6
        6
            4
4
            3
        3
            2
    2
            1
        1
            0


VALID

Size: 17

--Removing 11

            24
            23
        23
            22
        22
            21
    21
            18
        18
            17
        17
            16
16
            14
        14
            13
            12
    12
            6
        6
            4
4
            3
        3
            2
    2
            1
        1
            0


VALID

Size: 16

--Removing 0

            24
            23
        23
            22
        22
            21
    21
            18
        18
            17
        17
            16
16
            14
        14
            13
            12
    12
            6
        6
            4
    4
            3
        3
            2
        2
            1


VALID

Size: 15

--Removing 14

            24
            23
        23
            22
        22
            21
    21
            18
        18
            17
        17
            16
16
            13
        13
            12
    12
            6
        6
            4
    4
            3
        3
            2
        2
            1


VALID

Size: 14

--Removing 17

            24
            23
        23
            22
        22
            21
    21
            18
        18
            16
16
            13
        13
            12
    12
            6
        6
            4
    4
            3
        3
            2
        2
            1


VALID

Size: 13

--Removing 6

            24
            23
        23
            22
        22
            21
    21
            18
        18
            16
16
            13
        13
            12
    12
            4
        4
            3
    3
            2
        2
            1


VALID

Size: 12

--Removing 18

            24
            23
        23
            22
    22
            21
        21
            16
16
            13
        13
            12
    12
            4
        4
            3
    3
            2
        2
            1


VALID

Size: 11

--Removing 24

            23
        23
            22
    22
            21
        21
            16
16
            13
        13
            12
    12
            4
        4
            3
    3
            2
        2
            1


VALID

Size: 10

--Removing 1

            23
        23
            22
    22
            21
        21
            16
16
            13
        13
            12
    12
            4
        4
            3
        3
            2


VALID

Size: 9

--Removing 3

            23
        23
            22
    22
            21
        21
            16
16
            13
        13
            12
    12
            4
        4
            2


VALID

Size: 8

--Removing 13

        23
    23
        22
22
        21
    21
        16
16
        12
    12
        4
    4
        2


VALID

Size: 7

--Removing 2

        23
    23
        22
22
        21
    21
        16
16
        12
    12
        4


VALID

Size: 6

--Removing 23

        22
    22
        21
    21
        16
16
        12
    12
        4


VALID

Size: 5

--Removing 16

        22
    22
        21
21
        12
    12
        4


VALID

Size: 4

--Removing 12

    22
22
    21
21
    4


VALID

Size: 3

--Removing 22

    21
21
    4


VALID

Size: 2

--Removing 21

4


VALID

Size: 1

--Removing 4



VALID

Size: 0



----------------END TEST---------------

===============================
*/


#endif  // Z_OUTPUT_H_
