import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;

public class addingwords {
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
        Map<String, Integer> map = new HashMap<>();
        Map<Integer, String> map2 = new HashMap<>();
        while (true) {
            String s = br.readLine();
            if (s.length() == 0) {
                return;
            }
            String[] stuff = s.split(" ");
            if (stuff[0].equals("clear")) {
                map = new HashMap<>();
                map2 = new HashMap<>();
            } else if (stuff[0].equals("def")) {
                if (map2.containsKey(Integer.parseInt(stuff[2]))) {
                    map.remove(map2.get(Integer.parseInt(stuff[2])));
                }
                if (map.containsKey(stuff[1])) {
                    map2.remove(map.get(stuff[1]));
                }
                map.put(stuff[1], Integer.parseInt(stuff[2]));
                map2.put(Integer.parseInt(stuff[2]), stuff[1]);
            } else {
                StringBuilder sb = new StringBuilder();
                int fin = 0, prev = 1;
                boolean isUnknown = false;
                for (int i = 1; i < stuff.length; i++) {
                    sb.append(stuff[i]);
                    sb.append(" ");
                    if (i % 2 == 1) {
                        if (map.containsKey(stuff[i])) {
                            if (prev == 0) {
                                fin -= map.get(stuff[i]);
                            } else {
                                fin += map.get(stuff[i]);
                            }
                        } else {
                            isUnknown = true;
                        }
                    } else {
                        prev = (stuff[i].equals("+")) ? 1 : 0;
                    }
                }
                if (isUnknown || (!map2.containsKey(fin))) {
                    sb.append("unknown");
                } else {
                    sb.append(map2.get(fin));
                }
                sb.append("\n");
                writer.print(sb);
                writer.flush();
            }
        }
    }
}