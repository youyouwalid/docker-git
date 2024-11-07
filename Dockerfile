FROM alpine

WORKDIR /yoyo

COPY user.cpp .

RUN apk add --no-cache build-base

RUN g++ -o yoyo user.cpp


CMD ["./yoyo"]