import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Pair implements Comparable<Pair> {
    long x;
    int y;

    Pair(long x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int compareTo(Pair p) {
        if(this.x > p.x) {
            return 1;
        } else if (this.x == p.x) {
            if (this.y > p.y) {
                return 1;
            }
        }
        return -1;
    }
}

public class Main {
    public static boolean dijkstra(ArrayList<ArrayList<Pair>> graph, int start, int end, int total, int limit) {
        final int MAX = 11;
        final long INF = (long)(1e17+7);

        boolean[] visit = new boolean [MAX];
        long[] dist = new long [MAX];
        Arrays.fill(visit, false);
        Arrays.fill(dist, INF);

        PriorityQueue<Pair> que = new PriorityQueue<>();
        que.add(new Pair(0L, start));
        dist[start] = 0L;

        while (!que.isEmpty()) {
            Pair p = que.poll();
            long cost = p.x;
            int cur = p.y;

            if (visit[cur])
                continue;
            visit[cur] = true;

            for (int i=0; i<graph.get(cur).size(); ++i) {
                long next_cost = graph.get(cur).get(i).x;
                int next = graph.get(cur).get(i).y;

                if (next_cost <= limit && dist[next] > next_cost + cost) {
                    dist[next] = next_cost + cost;
                    que.add(new Pair(dist[next], next));
                }
            }
        }

        return dist[end] <= total;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        ArrayList<ArrayList<Pair>> graph = new ArrayList<>();
        for (int i=0; i<=n; ++i) {
            graph.add(new ArrayList<>());
        }

        for (int i=0; i<m; ++i) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int z = Integer.parseInt(st.nextToken());
            graph.get(u).add(new Pair(z, v));
            graph.get(v).add(new Pair(z, u));
        }

        if (dijkstra(graph, a, b, c, 10001)) {
            int l = 0, r = 10001;
            while (l <= r) {
                int mid = (l+r)/2;
                if (dijkstra(graph, a, b, c, mid)) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            System.out.println(l);
        } else {
            System.out.println(-1);
        }
    }
}
