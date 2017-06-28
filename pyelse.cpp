#include <pybind11/pybind11.h>
#include "pybind11_opencv_numpy/ndarray_converter.h"
#include "else/algo.h"


PYBIND11_PLUGIN(pyelse) {
	NDArrayConverter::init_numpy();
	pybind11::module m("pyelse", "python bindings for ELSE pupil detection");
	pybind11::class_<cv::RotatedRect>(m, "RotatedRect")
		.def_readwrite("center", &cv::RotatedRect::center);
	pybind11::class_<cv::Point_<float>>(m, "Point_float")
		.def_readwrite("x", &cv::Point_<float>::x)
		.def_readwrite("y", &cv::Point_<float>::y);
	m.def("run", ELSE::run, "run the detection");
	return m.ptr();
}
