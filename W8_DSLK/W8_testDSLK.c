#include <stdio.h>  // Thư viện cho các hàm nhập/xuất
#include <stdlib.h> // Thư viện cho các hàm cấp phát và giải phóng bộ nhớ như malloc và free
// Định nghĩa cấu trúc cho hạng tử của đa thức
struct Node {
    int heSo; // Hệ số của hạng tử
    int bac;  // Bậc của hạng tử
    struct Node* next; // Con trỏ tới hạng tử tiếp theo trong danh sách liên kết
};
// Hàm tạo một hạng tử mới cho đa thức
struct Node* taoHangTu(int heSo, int bac) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Cấp phát bộ nhớ cho hạng tử mới
    newNode->heSo = heSo; // Gán hệ số
    newNode->bac = bac; // Gán bậc
    newNode->next = NULL; // Đặt con trỏ next bằng NULL
    return newNode; // Trả về con trỏ đến hạng tử mới
}
// Hàm thêm một hạng tử vào đa thức
void themHangTu(struct Node** daThuc, int heSo, int bac) {
    struct Node* newNode = taoHangTu(heSo, bac); // Tạo hạng tử mới
    newNode->next = *daThuc; // Thêm hạng tử mới vào đầu danh sách
    *daThuc = newNode; // Cập nhật con trỏ đầu danh sách
}
// Hàm in đa thức theo định dạng
void inDaThuc(struct Node* daThuc) {
    int laHangTuDauTien = 1; // Biến để xử lý hạng tử đầu tiên
    while (daThuc != NULL) {
        if (!laHangTuDauTien && daThuc->heSo > 0) { // Kiểm tra nếu không phải hạng tử đầu tiên và hệ số lớn hơn 0
            printf(" + "); // In dấu cộng
        }
        printf("%dx^%d", daThuc->heSo, daThuc->bac); // In hệ số và bậc
        laHangTuDauTien = 0; // Đánh dấu không còn là hạng tử đầu tiên
        daThuc = daThuc->next; // Di chuyển đến hạng tử tiếp theo
    }
    printf("\n"); // Xuống dòng sau khi in xong đa thức
}
int main() {
    struct Node* f = NULL; // Khởi tạo đa thức f
    struct Node* g = NULL; // Khởi tạo đa thức g
    // Khởi tạo f(x) = x^10 + 1
    themHangTu(&f, 1, 10); // Thêm hạng tử x^10
    themHangTu(&f, 1, 0); // Thêm hạng tử 1 (x^0)
    // Khởi tạo g(x) = 10x^15 - 2x^7 + 3x^2 - 7
    themHangTu(&g, 10, 15); // Thêm hạng tử 10x^15
    themHangTu(&g, -2, 7); // Thêm hạng tử -2x^7
    themHangTu(&g, 3, 2); // Thêm hạng tử 3x^2
    themHangTu(&g, -7, 0); // Thêm hạng tử -7 (x^0)
    // In các đa thức
    printf("f(x) = ");
    inDaThuc(f); // In đa thức f
    printf("g(x) = ");
    inDaThuc(g); // In đa thức g
    return 0; // Kết thúc chương trình
}