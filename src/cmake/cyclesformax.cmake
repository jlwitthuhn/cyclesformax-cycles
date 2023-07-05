add_definitions(-D__TBB_NO_IMPLICIT_LINKAGE)
add_definitions("-DBOOST_ALL_NO_LIB")
add_definitions(-DFREEGLUT_STATIC)
add_definitions(-DGLEW_STATIC)
add_definitions(-DOIIO_STATIC_BUILD)
add_definitions(-DOIIO_STATIC_DEFINE)

set(MY_LIB_DIR "C:/Dev/CyclesMax/libs_autobuild/v140r/")

set(TBB_INCLUDE_DIR "${MY_LIB_DIR}/oneTBB-2021.3.0/include/")
set(TBB_LIBRARY "${MY_LIB_DIR}/oneTBB-2021.3.0/lib/tbb.lib")

set(PNG_PNG_INCLUDE_DIR "D${MY_LIB_DIR}/libpng-1.6.37/include/")
set(PNG_LIBRARY "${MY_LIB_DIR}/libpng-1.6.37/lib/libpng16_static.lib")

set(TIFF_INCLUDE_DIR "${MY_LIB_DIR}/libtiff-4.4.0/include/")
set(TIFF_LIBRARY "${MY_LIB_DIR}/libtiff-4.4.0/lib/tiff.lib")

set(JPEG_INCLUDE_DIR "${MY_LIB_DIR}/libjpeg-turbo-2.1.3/include/")
set(JPEG_LIBRARY "${MY_LIB_DIR}/libjpeg-turbo-2.1.3/lib/jpeg-static.lib")

set(ZLIB_INCLUDE_DIR "${MY_LIB_DIR}/zlib-1.2.12/include/")
set(ZLIB_LIBRARY "${MY_LIB_DIR}/zlib-1.2.12/lib/zlibstatic.lib")

set(GLUT_FOUND TRUE)
set(GLUT_INCLUDE_DIR "${MY_LIB_DIR}/freeglut-3.2.1/include/")
set(GLUT_LIBRARIES "${MY_LIB_DIR}/freeglut-3.2.1/lib/freeglut_static.lib")
set(GLUT_glut_LIBRARY "${MY_LIB_DIR}/freeglut-3.2.1/lib/freeglut_static.lib")

set(GLEW_INCLUDE_DIR "${MY_LIB_DIR}/glew-2.1.0/include/")
set(GLEW_LIBRARY "${MY_LIB_DIR}/glew-2.1.0/lib/libglew32.lib")
set(CYCLES_APP_GLEW_LIBRARY "${MY_LIB_DIR}/glew-2.1.0/lib/libglew32.lib")

set(OPENIMAGEIO_ROOT_DIR "${MY_LIB_DIR}/oiio-2.2.20.0/")

set(OPENEXR_ROOT_DIR "${MY_LIB_DIR}/openexr-2.5.8/")

set(BOOST_ROOT "${MY_LIB_DIR}/boost-1.78.0/")
set(BOOST_LIBRARYDIR "${MY_LIB_DIR}/boost-1.78.0/lib/")
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME OFF)
