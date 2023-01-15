import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;

public class sacredtexts {
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
            byte[] buf = new byte[101]; // line length
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
        String[] arr = br.readLine().split(" ");
        String initial = "`abcdefghijklmnopqrstuvwxyz";
        int firstChar = 0;
        for (int i = 0; i < arr[0].length(); ++i) {
            firstChar += (int)(arr[0].charAt(i)) - 32;
        }
        int index = 0;
        for (int i = 0; i < initial.length(); ++i) {
            if (initial.charAt(i) == arr[1].charAt(0)) {
                index = i;
                break;
            }
        }
        int offset = firstChar - index;
        offset %= 26;
        while (true) {
            StringBuilder build = new StringBuilder();
            String s = br.readLine();
            if (s.length() == 0) {
                return;
            }
            String[] arr2 = s.split(" ");
            for (int i = 0; i < arr2.length; ++i) {
                int num = 0;
                if (arr2[i].charAt(0) == '0') {
                    build.append(" ");
                } else if (arr2[i].charAt(0) == '<') {
                    build.append(",");
                } else if (arr2[i].charAt(0) == '>') {
                    build.append(".");
                } else {
                    for (int j = 0; j < arr2[i].length(); ++j) {
                        num += (int)(arr2[i].charAt(j)) - 32;
                    }
                    num -= offset;
                    num %= 26;
                    while (num <= 0) {
                        num += 26;
                    }
                    build.append(initial.charAt(num));
                }
            }
            build.append("\n");
            writer.print(build);
            writer.flush();
        }
    }
}