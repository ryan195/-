import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;

public class sailingfriends {
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[1000]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                buf[cnt++] = (byte)c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
    public static void main(String[] args) throws IOException {
        Reader br = new Reader();
        PrintWriter writer = new PrintWriter(System.out);
        int numPpl = br.nextInt(),
                boatsAvail = br.nextInt(),
                numFrens = br.nextInt();
        UnionFind ufds = new UnionFind(numPpl);
        for (int i = 0; i < boatsAvail; i++) {
            int boat = br.nextInt() - 1;
            ufds.addBoat(boat);
        }
        for (int i = 0; i < numFrens; i++) {
            int a = br.nextInt() - 1,
                    b = br.nextInt() - 1;
            ufds.unionSet(a, b);
        }
        int counter = 0;
        for (int i = 0; i < numPpl; i++) {
            if (ufds.hasBoat[ufds.findSet(i)] == 0) {
                counter += 1;
                ufds.addBoat(ufds.findSet(i));
            }
        }
        writer.print(counter);
        writer.flush();
    }
}

class UnionFind {
    int[] p;
    int[] hasBoat;
    UnionFind(int N) {
        p = new int[N];
        hasBoat = new int[N];
        for (int i = 0; i < N; i++) {
            p[i] = i;
            hasBoat[i] = 0;
        }
    }
    void addBoat(int i) {
        hasBoat[i] = 1;
    }
    int findSet(int i) {
        if (p[i] != i) {
            p[i] = findSet(p[i]);
        }
        return p[i];
    }
    boolean isSameSet(int a, int b) {
        return findSet(a) == findSet(b);
    }
    void unionSet(int a, int b) {
        int x = findSet(a), y = findSet(b);
        if (x == y) {
            return;
        }
        if ((hasBoat[x] == 1) && (hasBoat[y] == 0)) {
            p[y] = x;
        } else {
            p[x] = y;
        }
    }
}