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

# run tests
```
cmake -DBUILD_TESTS=ON .. 
cmake --build . 
ctest
```
