# ppm shaders

This is a collection of cool shaders that I have either found and re-implemented or created myself -- all written in c! This is just a fun little project. Feel free to use and share my code as you please, just please give credit where credit is due!

## dependencies

### if you just want to generate images

- [gcc](https://gcc.gnu.org/)
- [gnu make](https://www.gnu.org/software/make/)

### if you want to generate videos too

- [ffmpeg](https://ffmpeg.org/)

## generating images and videos

### all images and videos

```
make
```

### all images

```
make images
```

### all videos

```
make videos
```

### one image/video

```
cd src/bin/<whatever>
make image
```

or

```
cd src/bin/<whatever>
make video
```

## cleaning up generated images/videos

```
make clean
```
