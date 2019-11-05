#include <stdio.h>
#include <stdlib.h>



int rotate(int a[], int start, int end) {
    //int pos = 0;
    int m = start;
    int n = end;
    int pos = m;

    while (n > m) {
        //printf("%d-%d\n", n, m);
        //这里不用for，用while，因为n是要变得， 如果n不变可以用for
        for (int i = n; i > pos; i--, n--) {
            if (a[i] < a[pos]) {
                int tmp = a[pos];
                a[pos] = a[i];
                a[i] = tmp;

                pos = i;
                n = pos-1;
                m++;
                //printf("%d-%d-%d\n", pos, n, m);
                break;
            }
        }

        for (int i = m; i < pos; i++,m++) {
            if (a[i] > a[pos]) {
                int tmp = a[pos];
                a[pos] = a[i];
                a[i] = tmp;

                pos = i;
                m = pos+1;
                n--;
                break;
            }
        }
    }

    //printf("pos=%d\n", pos);
    return pos;
}

// 这里不是尾后指针
void fast_sort(int a[], int start, int end) {
    if (start >= end) {
        return;
    }

    int mid = rotate(a, start, end);
    fast_sort(a, start, mid-1);
    fast_sort(a, mid+1, end);
    return;
}


void sort_one(int a[], int start, int end) {

    int pos = start;
    while (pos < end) {
        int left = pos*2+1;
        int right = pos*2+2;
        int target = pos;

        if (left > end) {
            break;
        }

        if (a[left] > a[pos]) {
            target = left;
        }

        if (right < end && a[right] > a[target]) {
            target = right;
        }

        if (target == pos) {
            break;
        }

        int tmp = a[pos];
        a[pos] = a[target];
        a[target] = tmp;
        pos = target;
    }
}

void make_heap(int a[], int num) {
    for (int i = num -1; i>=0; i--) {
        sort_one(a, i, num-1);
    }
}

void heap_sort(int a[], int num) {
    make_heap(a, num);
    printf("make heap ok\n");

    for (int pos = num-1; pos > 0; pos--) {
        int tmp = a[pos];
        a[pos] = a[0];
        a[0] = tmp;

        sort_one(a, 0, pos-1);
    }

    return;
}

void insert(int a[], int num) {
    for (int i = 1; i < num; i++) {
        int tmp = a[i];
        int j = i-1;
        for (; j >= 0; j--) {
            if (a[j] > tmp) {
                a[j+1] = a[j];
            } else {
                break;
            }
        }

        a[j+1] = tmp;
    }
}

void pubble_sort(int a[], int num) {
    for (int i = num -1; i >0; i--) {
        bool change = false;

        for (int j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                change = true;
            }
        }

        if (!change) {
            break;
        }
    }
}

void merge_sort(int a[], int start, int end) {
    printf("do start=%d, end=%d\n", start, end);

    if (start == end) {
        return;
    }

    void* tmp = malloc(sizeof(int)*(end-start+1));
    int* save = (int*)tmp;

    int mid = (start+end)/2;
    merge_sort(a, start, mid);
    merge_sort(a, mid+1, end);


    int i = start;
    int j = mid+1;
    int k = 0;

    for (int t = start; t <= mid; t++){
        printf("part1:");
        printf("%d ", a[t]);
    }

    for (int t = mid+1; t <= end ; t++ ) {
        printf("part2:");
        printf("%d ", a[t]);
    }

    for (; i <= mid && j <= end; k++) {
        if (a[i] <= a[j]) {
            save[k] = a[i];
            i++;
            //continue;
        } else {
            save[k] = a[j];
            j++;
            //continue;
        }
    }

    if (i <= mid) {
        for (;i<= mid; i++, k++) {
            save[k] = a[i];
        }
    } else {
        for (; j<=end; j++, k++) {
            save[k] = a[j];
        }
    }

    /* fuck 这里只能写本次归并的！！！
    while (--k>=0) {
        a[k] = save[k];
    }
     */

    for (int t = start, q=0; t <= end; t++, q++) {
        a[t] = save[q];
    }

    int len = end-start+1;
    printf("%d, %d, %d\n", start, end, mid);
    for (int m = 0; m < len; m++) {
        printf("%d ", a[m]);
    }
    printf("\n");

    free(save);

    return;
}

int main() {
    int a[10] = {12, 33, 4, 6, 8, 88, 3, 99, 58, 11};

    //fast_sort(a, 0, 9);
    //heap_sort(a, 10);
    //insert(a,10);
    merge_sort(a, 0, 9);

    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}