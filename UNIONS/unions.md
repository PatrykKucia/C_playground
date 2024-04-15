# UNIONS
[Go Back to main page](../README.md)

The Union is a user-defined data type in C language that can contain elements of the different data types just like structure. But unlike structures, all the members in the C union are stored in the same memory location. Due to this, only one member can store data at the given instance.
## SYNTAX
```
union union_name {
    datatype member1;
    datatype member2;
    ...
};
```
## TIPS

->for a function to change the acctual value in a union memory location, pointers parameters are required
## EXAMPLES

->you can use Unions to access individual bit 
