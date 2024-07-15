# start
```
rm -rf build
mkdir build
cd build/
```

# build app
```
cmake ..
cmake --build .
```

# run app on Linux
```
./ExampleApp
```

# run app on Windows
```
./Debug/ExampleApp.exe
```

# build and run tests
```
cmake -DBUILD_TESTS=ON ..
cmake --build .
ctest
```
