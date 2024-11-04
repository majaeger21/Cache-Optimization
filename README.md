###Purpose
To optimize data cache accesses for the matrix multiply application.

###Measurements
You can measure the number of cache misses and cache references using:
    perf stat -e cache-misses -e cache-references ./mm > myout



