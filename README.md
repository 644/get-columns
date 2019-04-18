Parse malformed table data and format as CSV

Input:
```
   Oil           0           barrels               0         barrels
  Brine                      barrels               0         barrels
  Other            5                        0         barrels
```

Output:
```
"0","barrels","0","barrels","","","","barrels","0","barrels","","","5","","0","barrels","","",
```
