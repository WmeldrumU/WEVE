include .env
ifeq ($(OS),Windows_NT) 
RM = del /Q /F
CP = copy /Y
ifdef ComSpec
SHELL := $(ComSpec)
endif
ifdef COMSPEC
SHELL := $(COMSPEC)
endif
else
RM = rm -rf
CP = cp -f
endif
CFLAGS = -std=c++17 -I. -I${VULKAN_SDK_PATH_INCLUDE} -I${GLM_INCLUDE} -I${GLFW_INCLUDE}
LDFLAGS = -L${GLFW_LIB} -L${VULKAN_SDK_PATH_LIB} -lglfw3 -lvulkan-1 -lgdi32 
TARGET = main.exe
${TARGET}: src/main.cpp
	g++ $(CFLAGS) -o ${TARGET} src/main.cpp  $(LDFLAGS)
.PHONY: test clean
test: ${TARGET}
	.\${TARGET}
clean:
	${RM} .\${TARGET}