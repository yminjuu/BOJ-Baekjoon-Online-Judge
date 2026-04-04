function solution(){
    const input= require("fs").readFileSync(0).toString().trim().split(/\s+/);

    let N= Number(input[0]);
    let M= Number(input[1]);

    let degree= new Array(N+2).fill(0); // 진입차수 저장
    let edge = Array.from({length: N+1}, ()=> []);

    for (let ptr=2; ptr< 2*(M+1); ptr+=2){
        let a = Number(input[ptr]); let b= Number(input[ptr+1]);
        edge[a].push(b);
        degree[b]++;
    }

    let visited = new Array(N+1).fill(0);
    let ans = [];

    let cnt=0;
    while (true){
        let nodes = [];
        for (let i=1; i<=N; i++){
            if (degree[i]==0 && visited[i]==0) {
                visited[i]= 1;
                nodes.push(i);
            }
        }

        for (let i=0; i<nodes.length; i++) {
            ans.push(nodes[i]);
            for (let j=0; j<edge[nodes[i]].length; j++){
                let next = edge[nodes[i]][j];
                degree[next]--;
            }
        }

        if (ans.length==N) break;
    }

    console.log(ans.join(" "));
}

// js- 위상정렬 (진입차수를 사용)
solution();