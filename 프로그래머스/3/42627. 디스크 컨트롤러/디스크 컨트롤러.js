class PriorityQueue {
        constructor(comparator = (a,b) => a-b) {
            this.heap = [];
            this.comparator = comparator;
        }
    
        push(value) {
            this.heap.push(value);
            this.bubbleUp();
        }
        pop() {
            if (this.heap.length===0) return undefined;
            if (this.heap.length===1) return this.heap.pop();
            
            const next = this.heap[0];
            this.heap[0] = this.heap.pop();
            this.bubbleDown();
            
            return next;
        }
        bubbleUp(){
            let index = this.heap.length - 1;
            
            while (index>0) {
                let parent = Math.floor((index-1) / 2);
                if (this.comparator(this.heap[index], this.heap[parent]) < 0){
                    [this.heap[index], this.heap[parent]]= [this.heap[parent], this.heap[index]];
                    index= parent;
                } else break;
            }
        }
        bubbleDown(){
            let index = 0;
            let length = this.heap.length;
            
            while (true){
                let left = (index) * 2 +1;
                let right = (index) * 2 +2;
                let upper= index;
                
                if (left<length && this.comparator(this.heap[left], this.heap[upper]) < 0) upper= left;
                if (right<length && this.comparator(this.heap[right], this.heap[upper]) < 0) upper= right;
                
                if (upper==index) break;
                
                [this.heap[upper], this.heap[index]] = [this.heap[index], this.heap[upper]];
                index= upper;
            }
        }
        length(){
            return this.heap.length;
        }
}

class Task {
    constructor(index, requestTime, runTime){
        this.index= index;
        this.requestTime= requestTime;
        this.runTime= runTime;
    }
}

function solution(jobs) {
    var answer = 0;
       
    const comparator = (a,b) => {
        return a.runTime - b.runTime || a.requestTime - b.requestTime || a.index - b.index;
    }
    
    const pq = new PriorityQueue(comparator);
    jobs.sort((a,b) => a[0] - b[0]);
    
    let jobIdx= 0;
    let time= 0;
    while (jobIdx < jobs.length || pq.length()!=0){
        while (jobIdx < jobs.length && time >= jobs[jobIdx][0]) {
            // 넣을 수 있는 만큼 넣는다
            pq.push(new Task(jobIdx, jobs[jobIdx][0], jobs[jobIdx][1]));
            jobIdx++;
        }
        
        // 다음 작업을 선택한다
        const next = pq.pop();
    
        if (next===undefined) {
            time= jobs[jobIdx][0]; // 요청시각으로 바로 보냄
            continue;
        }
        
        answer += (time+next.runTime)-next.requestTime;
        time += next.runTime;
    }
    
    return Math.floor(answer / jobs.length);
}