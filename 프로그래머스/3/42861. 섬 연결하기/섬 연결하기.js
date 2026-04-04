// union-find 사용 => prim 알고리즘

let parent = [];

// a의 부모 찾기
function find(a){
    if (parent[a]==a) return a;
    else return parent[a] = find(parent[a]);
}

// a집합과 b집합 합치기
function unionFunc(a, b){
    let parentA= find(a);
    let parentB= find(b);
    
    if (parentA!=parentB) parent[parentA]= parentB;
}

function solution(n, costs) {
    var answer = 0;
    
    for (let i=1; i<=n; i++){
        parent[i]= i;
    }
    
    costs.sort((a,b) => a[2] - b[2]); // 비용 작은 순서대로 정렬
    
    for (let i=0; i<costs.length; i++){
        const [a,b,cost]= costs[i];
        
        if (find(a)!=find(b)) {
            unionFunc(a,b);
            answer+=cost;
        }
    }
    
    return answer;
}