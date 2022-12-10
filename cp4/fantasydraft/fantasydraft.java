import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class fantasydraft {
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
            byte[] buf = new byte[20000]; // line length
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
        String[] line = br.readLine().split(" ");
        int numOwners = Integer.parseInt(line[0]), teamSize = Integer.parseInt(line[1]);
        List<Owner> lst = new ArrayList<>();
        for (int i = 0; i < numOwners; i++) {
            String[] preSelectLine = br.readLine().split(" ");
            lst.add(new Owner());
            for (int j = 1; j < preSelectLine.length; j++) {
                lst.get(i).preference.add(preSelectLine[j]);
            }
        }
        Map<String, Boolean> playerTaken = new HashMap<>();
        List<String> playerLst = new ArrayList<>();
        int numPlayers = Integer.parseInt(br.readLine());
        for (int i = 0; i < numPlayers; i++) {
            String player = br.readLine();
            playerTaken.put(player, false);
            playerLst.add(player);
        }
        int overallIndex = 0;
        for (int i = 0; i < teamSize; i++) {
            for (int j = 0; j < numOwners; j++) {
                Owner curr = lst.get(j);
                boolean gotPlayer = false;
                while (curr.index < curr.preference.size()) {
                    if (!playerTaken.get(curr.preference.get(curr.index))) {
                        playerTaken.put(curr.preference.get(curr.index), true);
                        curr.team.add(curr.preference.get(curr.index));
                        gotPlayer = true;
                        curr.index++;
                        break;
                    } else {
                        curr.index++;
                    }
                }
                while (!gotPlayer) {
                    if (!playerTaken.get(playerLst.get(overallIndex))) {
                        playerTaken.put(playerLst.get(overallIndex), true);
                        curr.team.add(playerLst.get(overallIndex));
                        gotPlayer = true;
                        overallIndex++;
                    } else {
                        overallIndex++;
                    }
                }
            }
        }
        StringBuilder build = new StringBuilder();
        for (int i = 0; i < numOwners; i++) {
            for (int j = 0; j < teamSize; j++) {
                build.append(lst.get(i).team.get(j));
                build.append(" ");
            }
            build.append("\n");
        }
        writer.print(build);
        writer.flush();
    }
}

class Owner {
    List<String> team;
    List<String> preference;
    int index;
    Owner() {
        this.team = new ArrayList<>();
        this.preference = new ArrayList<>();
        this.index = 0;
    }
}