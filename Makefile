.PHONY: all images videos clean

all: images videos

images:
	for DIR in $$(ls src/bin); do \
		cd src/bin/$$DIR && make image; \
	done

videos:
	for DIR in $$(ls src/bin); do \
		cd src/bin/$$DIR && make video; \
	done

clean:
	rm -rf build output
