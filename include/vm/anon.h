#ifndef VM_ANON_H
#define VM_ANON_H
#include "vm/vm.h"
#include "lib/kernel/bitmap.h"
struct page;
enum vm_type;

// anonymous page는 file-backed page와 달리 contents를 가져올 file이나 device가 없는 page를 말한다. 이들은 프로세스 자체에서 런타임 때 만들어지고 사용된다. stack 과 heap 영역의 메모리들이 여기에 해당된다.
struct anon_page {
    //struct page anon_p;
    int swap_sector; // swap된 내용이 저장되는 sector
};

// [include>vm>anon.h] 추가
struct bitmap *swap_table; // 0 - empty, 1 - filled
int bitcnt;

void vm_anon_init (void);
bool anon_initializer (struct page *page, enum vm_type type, void *kva);

#endif
