pyelse.so: pyelse.cpp pybind11_opencv_numpy/ndarray_converter.cpp
	c++ -O3 -fPIC -shared -std=c++11 `pkg-config python3 opencv --cflags --libs` $^ -o $@

