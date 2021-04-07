#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool checkSoNguyenTo(int a);
void nhapMaTran(int a[][100], int n);
void xuatMaTran(int a[][100], int n);
float tinhTrungBinhCongSoNguyenTo(int a[100][100], int m, int n);
float tinhTrungBinhCongSoHoanThien(int a[100][100], int n);

void nhapMaTran(int a[][100], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
}

void xuatMaTran(int a[][100], int n)
{
    for (int i = 0; i < n ;i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

bool checkSoHoanThien(int n)
{
    int sum = 0; //khai bao biem sum
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n)
        return true; // tra ve true
    return false;
}

bool checkSoNguyenTo(int a)
{
    if (a <= 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

// Tinh trung binh cong cac so nguyen o bien
float tinhTrungBinhCongSoNguyenTo(int a[100][100], int n)
{
    int s = 0, av = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkSoNguyenTo(a[i][0]))
        {
            s += a[i][0];
            av++;
        }

        if (checkSoNguyenTo(a[i][n - 1]))
        {
            s += a[i][n - 1];
            av++;
        }
    }
    for (int j = 1; j < n - 1; j++)
    {
        if (checkSoNguyenTo(a[0][j]))
        {
            s += a[0][j];
            a++;
        }
        if (checkSoNguyenTo(a[n - 1][j]))
        {
            s += a[n - 1][j];
            av++;
        }
    }
    return ((float)s / av);
}

// Tinh trung binh cong so hoan thien tren duong cheo chinh
float tinhTrungBinhCongSoHoanThien(int a[100][100], int n)
{
    int s = 0, av = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkSoHoanThien(a[i][i]))
        {
            s += a[i][i];
            av++;
        }
    }
    return ((float)s / av);
}

void docMaTranTuFile()
{
    FILE *fp;
    int row, col, i, j;
    int matrix[10][10];
    fp = fopen("M1.txt", "r");

    // doc so hang cua ma tran
    fscanf(fp, "%d\n", &row);
    // doc so cot cua ma tran
    fscanf(fp, "%d\n", &col);

    printf("So hang cua ma tran: %d\n", row);
    printf("So cot cua ma tran: %d\n", col);
    if(row == col){
        printf("Day la ma tran vuong");
    }

    // doc noi dung ma tran
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fscanf(fp, "%d\n", &matrix[i][j]);
        }
    }

    printf("\nMa tran: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    fclose(fp);
}

void menu()
{
    printf("Nhap 0: Ket thuc chuong trinh\n");
    printf("Nhap 1: Nhap ma tran\n");
    printf("Nhap 2: Xuat ma tran\n");
    printf("Nhap 3: Tinh trung binh cong cua cac so tren duong bien cua ma tran\n");
    printf("Nhap 4: Tinh trung binh cong cac so hoan thien tren duong cheo chinh cua ma tran\n");
    printf("Nhap 5: Hien thi ma tran tu file");
    printf("Moi ban chon: ");
}

int main()
{

    int select = 0;
    int a[100][100];
    int m, n; // so Hang va Cot
    do
    {
        /* code */
        menu();
        printf("====================================================");
        scanf("%d", &select);
        switch (select)
        {
        case 0:
            exit(0);
        case 1:
        {
            printf("Ma tran cap? = ");
            scanf("%d", &n);
            printf("nhap vao ma tran:\n");
            nhapMaTran(a, n);
            break;
        }
        case 2:
        {
            xuatMaTran(a, n);
            break;
        }
        case 3:
        {
            printf("Trung binh cong cua duong bien la: %.2f", tinhTrungBinhCongSoNguyenTo(a, n));
            break;
        }
        case 4:
        {
            printf("Trung binh cong cac so hoan thien tren duong cheo chinh la %.2f", tinhTrungBinhCongSoHoanThien(a, n));
            break;
        }

        case 5:
        {
            printf("Hien thi ma tran tu file");
            docMaTranTuFile();
            break;
        }

        default:
            printf("Chuc nang khong co trong chuong trinh, moi ban nhap lai\n");
        }

    } while (select != 0);
}
