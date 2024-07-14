# start
```
rm -rf build 
mkdir build
cd build/
```

# run app
```
cmake .. 
cmake --build . 
./ExampleApp
```

# test run
```
cmake -DBUILD_TESTS=ON .. 
cmake --build . 
ctest
```
