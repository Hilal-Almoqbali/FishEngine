cp ./build_test_cmake_file/CMakeLists.txt ..
cd ..
mkdir build_test
cd ./build_test/
cmake ..
make -j 8
rm ../CMakeLists.txt
