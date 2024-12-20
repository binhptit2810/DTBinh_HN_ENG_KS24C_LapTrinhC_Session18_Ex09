#include <stdio.h>
#include <string.h>

struct Dish{
    int id;
    char name[50];
    int price;
};

int main() {
    int choice;
    struct Dish menu[100] = {
        {1, "Ga Ran", 149},
        {2, "Pho bo", 35},
        {3, "Com rang", 30},
        {4, "Rau Xao", 20},
        {5, "Bun cha", 25}
    };
    struct Dish temp;
    int n = 5;

    do {
        printf("\n      MENU      \n");
        printf("1. In ra gia tri cac phan tu co trong menu mon an\n");
        printf("2. Them mot phan tu vao mang\n");
        printf("3. Sua 1 phan tu o vi tri chi dinh\n");
        printf("4. Xoa 1 phan tu o vi tri chi dinh\n");
        printf("5. Sap xep cac phan tu tang dan theo price\n");
        printf("6. Tim kiem phan tu theo name nhap vao(tim kiem tuyen tinh)\n");
        printf("7. Thoat\n");
        printf("Moi ban nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
        	// in danh sach mon an ra ngoai man hinh 
            case 1: 
                for (int i = 0; i < n; i++) {
                    printf("id: %d, Ten mon an : %s, Gia tien : %d k\n", menu[i].id, menu[i].name, menu[i].price);
                }
                break;
            case 2: 
            // them mon an vao trong danh sach 
            	if (n >= 100) {
            		printf("Danh sach da day khong the them mon an\n");
            	} else {
                    printf("Moi ban nhap ten mon an: ");
                    getchar(); 
                    fgets(menu[n].name, sizeof(menu[n].name), stdin);
                    menu[n].name[strcspn(menu[n].name, "\n")] = 0; 
                    printf("Moi ban nhap gia mon an: ");
                    scanf("%d", &menu[n].price);
                    menu[n].id = n + 1;
                    n++;
                    printf("Da them mon an thanh cong\n"); 
                }
                break;
            case 3: { 
            // sua 1 mon an o vi tri chi dinh 
                int vitri;
                printf("Nhap vi tri muon sua: ");
                scanf("%d", &vitri);
                getchar();  
                if(vitri >= 1 && vitri <= n){
                    vitri--; 
                    printf("Moi ban nhap ten moi cua mon an: ");
                    fgets(menu[vitri].name, sizeof(menu[vitri].name),stdin);
                    menu[vitri].name[strcspn(menu[vitri].name, "\n")] = 0; 
                    printf("Moi ban nhap gia tien moi: ");
                    scanf("%d", &menu[vitri].price);
                } else {
                    printf("Vi tri khong hop le\n");
                }
                break;
            }
            case 4: { 
            // xoa 1 mon an o vi tri chi dinh
                int vitri;
                printf("Nhap vi tri muon xoa: ");
                scanf("%d",&vitri);
                if (vitri >= 1 && vitri <=n){
                    vitri--;  
                    for (int i = vitri; i <n - 1;i++){
                        menu[i] = menu[i + 1];
                    }
                    n--;
                } else {
                    printf("Vi tri khong hop le\n");
                }
                break;
            }
            case 5: 
            // sap xep mon an theo gia tien tang dan
                for (int i = 0;i < n -1; i++){
                    for (int j = i +1; j < n;j++){
                        if (menu[i].price > menu[j].price){
                            temp = menu[i];
                            menu[i] = menu[j];
                            menu[j] = temp;
                        }
                    }
                }
                printf("Da sap xep mon an theo gia tien tang dan\n");
                break;
            case 6: { 
            // tim kiem mon an theo name (tim kiem tuyen tinh)
                char searchName[50];
                printf("Moi ban nhap ten mon an can tim: ");
                getchar();  
                fgets(searchName, sizeof(searchName),stdin);  
                searchName[strcspn(searchName, "\n")] = 0; 
                int found = 0;
                for (int i = 0;i < n;i++) {
                    if (strcmp(menu[i].name, searchName) == 0) {
                        printf("Tim thay: id: %d, Ten mon an: %s, Gia mon an: %d k\n",menu[i].id, menu[i].name, menu[i].price);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Khong tim thay mon an\n");
                }
                break;
            }
            case 7: 
                printf("Ket thuc chuong trinh\n");
                break;
            default: 
                printf("Lua chon khong hop le! Vui long chon lai\n");
        }
    } while (choice != 7);

    return 0;
}

