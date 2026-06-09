### ARRAYS ###

Array is a linear Data Structure, Same type of elements stored in continious memory.You can access elements using its index.

*** Creating an Arr ***
int marks [50]. or int marks [50]={1,2,3,4} or int marks []={1,2,3} ( this is not dynamic its assigns 3 at comile time and stays same)

*** Size of Array ***
 
say int marks [5]={1,2,3,4,5}
 sizeof(marks) will be equal to 20 ( because 4 bit int type and 5 values so 4x5=20)

 if you want length of array : sizeof(marks)/sizeof(int). (Note- Index starts from 0)


 *** Passing Values ***
  in c++ : by Default values are passed by Val ( ie a copy of original is passed into a function any modification that happens inside function will not be updated on the real variable)

  to be able to do that u will have to pass by reference using pointers 

  However in Arrays values are passed by REF. ( pasisng an array into a function is same as *ptr [] and the dereferencing etc) 
