#include <iostream>
#include <vector>

using namespace std;

//전위: 루트 > 왼쪽 > 오른쪽
    //루트보다 큰 수가 나오는 순간 오른쪽 범위로 넘어감
//후위: 왼쪽 > 오른쪽 > 루트
    //범위 내에서는 오름차순 정렬
vector<int> tree;
vector<int> post_order;

void changeOrder(int start, int end){
    //탈출조건
    if (start >= end){
        return;
    }
   
    //루트보다 큰 노드의 직전 인덱스 계산
    int idx = start + 1;
    int root = tree[start];
    
    while (idx < end){
        if (root < tree[idx]){
            //cout << root << tree[idx] << "break 됨 \n";
            break;
        }
        idx++;
    }
    //cout <<"root = " << root << '\n';
    
    // 왼쪽 부분 저장
    changeOrder(start+1,idx);
    //cout << "왼쪽 완료\n";
    // 오른쪽 부분 저장
    changeOrder(idx, end);
    
    //바로 출력 대신벡터에 저장
    post_order.push_back(root);


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int num;
    //전위순회 입력
    while (cin >> num) {
		tree.push_back(num);
	}

    //후위순회 변경
    changeOrder(0, tree.size());

    //출력
    for (int i = 0; i < post_order.size(); i++){
        cout << post_order[i] << "\n";
    }
    

    return 0;
}
