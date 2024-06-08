// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

#define MAX_NODES 100
#define INF 999999

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    Edge* edges[MAX_NODES];
    int num_edges[MAX_NODES];
} Graph;

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < MAX_NODES; ++i) {
        graph->edges[i] = NULL;
        graph->num_edges[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int u, int v, int weight) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));
    edge->node = v;
    edge->weight = weight;
    graph->edges[u] = (Edge*)realloc(graph->edges[u], (graph->num_edges[u] + 1) * sizeof(Edge));
    graph->edges[u][graph->num_edges[u]++] = *edge;
}

int minDistance(int distance[], bool visited[], int n) {
    int min = INF, min_index;
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && distance[i] <= min) {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(Graph* graph, int src, int dest, int n) {
    int distance[MAX_NODES];
    bool visited[MAX_NODES];

    for (int i = 0; i < n; ++i) {
        distance[i] = INF;
        visited[i] = false;
    }

    distance[src] = 0;

    for (int count = 0; count < n - 1; ++count) {
        int u = minDistance(distance, visited, n);
        visited[u] = true;

        for (int i = 0; i < graph->num_edges[u]; ++i) {
            int v = graph->edges[u][i].node;
            int weight = graph->edges[u][i].weight;
            if (!visited[v] && distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    printf("%d\n", distance[dest]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Graph* graph = createGraph();

    for (int i = 0; i < m; ++i) {
        int u, v, q;
        scanf("%d %d %d", &u, &v, &q);
        addEdge(graph, u - 1, v - 1, q);
        addEdge(graph, v - 1, u - 1, q);
    }

    dijkstra(graph, 0, n - 1, n);

    return 0;
}

// "Ngưu Lang là vị thần chăn trâu của Ngọc Hoàng Thượng đế, vì say mê một tiên nữ phụ trách việc dệt vải tên là Chức Nữ nên bỏ bễ việc chăn trâu, để trâu đi nghênh ngang vào điện Ngọc Hư. Chức Nữ cũng vì mê tiếng tiêu của Ngưu Lang nên trễ nải việc dệt vải. Ngọc Hoàng giận dữ, bắt cả hai phải ở cách xa nhau, người đầu sông Ngân, kẻ cuối sông.

// Mỗi năm một lần, Sau đó, Ngọc Hoàng thương tình nên ra ơn cho hai người mỗi năm được gặp nhau vào ngày 7 tháng Bảy âm lịch. Khi tiễn biệt nhau, Ngưu Lang và Chức Nữ khóc sướt mướt. Nước mắt của họ rơi xuống trần hóa thành cơn mưa và được người dưới trần gian đặt tên là mưa ngâu." (Theo wikipedia.com)

// Để gặp được nhau vào ngày 7/7, Ngưu Lang và Chức Nữ phải nhờ đến bầy quạ đen bắt cầu (gọi là Ô kiều) cho mình đi qua để gặp nhau.

// Sông Ngân Hà có n ngôi sao, giả sử được đánh số từ 1 đến n. Ngưu Lang ở tại ngôi sao Ngưu (Altair), được đánh số 1, còn Chức Nữ ở tại ngôi sao Chức Nữ (Vega) được đánh số n. Để bắt được một cây cầu từ ngôi sao này sang ngôi sao kia cần một số lượng quạ nào đó. Một khi con quạ ở cây cầu nào thì phải ở đó cho đến khi Ngưu Lang và Chức Nữ gặp được nhau.

// Quạ thì càng ngày càng hiếm, nên Ngưu Lang và Chức Nữ phải tính toán sao cho số lượng quạ ít nhất có thể.

// Hãy giúp Ngưu Lang và Chức Nữ viết chương trình tính xem cần phải nhờ đến ít nhất bao nhiêu con quạ để bắt cầu cho họ gặp nhau.

// Đầu vào (Input):

// Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

// - Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số ngôi sao và số cặp sao có thể bắt cầu.

// - m dòng tiếp theo mỗi dòng chứa 3 số nguyên u v q nói rằng để bắt 1 cây cầu bắt qua hai ngôi sao u và v cần phải tốn q con quạ.

// Đầu ra (Output):

// In ra màn hình số lượng quạ cần thiết.

// Xem thêm ví dụ bên dưới.

// For example:

// Input	Result
// 4 3
// 1 2 5
// 2 3 2
// 3 4 1
// 8
// 4 3
// 1 2 3
// 2 4 4
// 1 4 10
// 7