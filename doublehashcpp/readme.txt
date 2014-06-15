1. hashtable c++ implementation devc++ project
2. integer datatype input output
3. select choice to do things
4. in terminal you can compile with command g++ doublehash.cpp main.cpp doublehash.h element.cpp element.h
5. run with command ./a.out and follow screen instructions
6. to give input from file and take output into file use command ./a.out <input.txt >output.txt
7. hash function used-(i mod n*k)+1=bucket_number
(bucket_number-1)modn= hashindex1
hashindex2 = (bucket_number-1)-n*hashindex1;
bucket_number= i1*n+i2+1
where i1 = hashindex1(firstindex of three dimensional array)
i2= hashindex2(second index of the array)
n is such that dh1[n][k]is a bucket which contains localcount[i1][i2] number of entries