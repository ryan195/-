import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class distracted {
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
            byte[] buf = new byte[800]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    } else {
                        continue;
                    }
                }
                buf[cnt++] = (byte) c;
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
        String[] s = br.readLine().split(" ");
        int numPpl = Integer.parseInt(s[0]);
        int numLooks = Integer.parseInt(s[1]);
        List<String> lines = new ArrayList<>();
        Map<String, Character> map = new HashMap<>();
        for (int i = 0; i < numPpl; i++) {
            String[] line = br.readLine().split(" ");
            map.put(line[0], line[1].charAt(0));
        }
        boolean unknown = false;
        for (int i = 0; i < numLooks; i++) {
            String ss = br.readLine();
            lines.add(ss);
            String[] line = ss.split(" ");
            String from = line[0];
            String to = line[2];
            if ((map.get(from) == 'm') && (map.get(to) == 'u')) {
                writer.print('1');
                writer.flush();
                return;
            } else if ((map.get(from) == '?') && (map.get(to) == 'u')) {
                unknown = true;
                map.put(from, 'u');
            } else if ((map.get(from) == 'm') && (map.get(to) == '?')) {
                unknown = true;
                map.put(to, 'm');
            } else if ((map.get(from) == '?') && (map.get(to) == '?')) {
                unknown = true;
            }
        }
        for (int i = 0; i < numLooks; i++) {
            String[] line = lines.get(i).split(" ");
            String from = line[0];
            String to = line[2];
            if ((map.get(from) == 'm') && (map.get(to) == 'u')) {
                writer.print('1');
                writer.flush();
                return;
            } else if ((map.get(from) == '?') && (map.get(to) == 'u')) {
                unknown = true;
                map.put(from, 'u');
            } else if ((map.get(from) == 'm') && (map.get(to) == '?')) {
                unknown = true;
                map.put(to, 'm');
            } else if ((map.get(from) == '?') && (map.get(to) == '?')) {
                unknown = true;
            }
        }
        writer.print(unknown ? '?' : '0');
        writer.flush();
    }
}