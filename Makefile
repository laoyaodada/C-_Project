BUILD_DIR   = ./build
TARGET_NAME = ./build/C++_Project/main
all: build
	cd $(BUILD_DIR); make
run:
	$(TARGET_NAME)
build:
	mkdir $(BUILD_DIR);cd $(BUILD_DIR); cmake ..
	cd ../
clean:
	rm $(BUILD_DIR) -rf
