PROJECT = checkerboard
ROOT = ../../..
EXECUTABLE = ${ROOT}/build/${PROJECT}
OUTPUT_DIR = ${ROOT}/output/${PROJECT}

.PHONY: all image video clean

all: image video

${EXECUTABLE}: main.c
	mkdir -p ${ROOT}/build
	gcc -I ${ROOT}/src/lib -o ${EXECUTABLE} $<

image: ${EXECUTABLE}
	${EXECUTABLE}
	mkdir -p ${OUTPUT_DIR}
	mv *.ppm ${OUTPUT_DIR}

video: ${EXECUTABLE}
	${EXECUTABLE} --video
	mkdir -p ${OUTPUT_DIR}
	ffmpeg -y -i output-%03d.ppm -r 60 ${OUTPUT_DIR}/${PROJECT}.mp4
	rm *.ppm

clean:
	rm -rf ${EXECUTABLE} ${OUTPUT_DIR}
