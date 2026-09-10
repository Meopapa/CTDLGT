## CTDL-GT

Thư viện C cho cấu trúc dữ liệu và thuật toán, sử dụng macro để tạo kiểu generic.

### Build và test

```sh
cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

Các module hiện có instance `int` để kiểm thử:

- stack cố định 8 phần tử
- queue vòng cố định 8 phần tử
- tensor 3 chiều
- binary search tree
- quicksort và binary search
- linked list đôi
- min-heap cố định
- graph ma trận kề với BFS
- AVL tree

Các header trong `include/` chứa API và macro khai báo; mã triển khai nằm trong `src/`.
