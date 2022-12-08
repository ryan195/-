import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class raidteams {
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
        int numPlayers = Integer.parseInt(br.readLine());
        TreeSet<Player> setA = new TreeSet<>(new Comparator<Player>() {
            @Override
            public int compare(Player o1, Player o2) {
                if (o1.a > o2.a) {
                    return -1;
                } else if (o1.a < o2.a) {
                    return 1;
                } else {
                    return o1.name.compareTo(o2.name);
                }
            }
        });
        TreeSet<Player> setB = new TreeSet<>(new Comparator<Player>() {
            @Override
            public int compare(Player o1, Player o2) {
                if (o1.b > o2.b) {
                    return -1;
                } else if (o1.b < o2.b) {
                    return 1;
                } else {
                    return o1.name.compareTo(o2.name);
                }
            }
        });
        TreeSet<Player> setC = new TreeSet<>(new Comparator<Player>() {
            @Override
            public int compare(Player o1, Player o2) {
                if (o1.c > o2.c) {
                    return -1;
                } else if (o1.c < o2.c) {
                    return 1;
                } else {
                    return o1.name.compareTo(o2.name);
                }
            }
        });
        Set<Player> setD = new HashSet<>();
        for (int i = 0; i < numPlayers; i++) {
            String[] stuff = br.readLine().split(" ");
            Player player = new Player(stuff[0], Long.parseLong(stuff[1]),
                    Long.parseLong(stuff[2]), Long.parseLong(stuff[3]));
            setA.add(player);
            setB.add(player);
            setC.add(player);
            setD.add(player);
        }
        StringBuilder build = new StringBuilder();
        for (int i = 0; i < numPlayers; i+=3) {
            if (numPlayers - i >= 3) {
                List<String> team = new ArrayList<>();
                Player aPlayer = setA.pollFirst();
                while (!setD.contains(aPlayer)) {
                    aPlayer = setA.pollFirst();
                }
                setD.remove(aPlayer);
                team.add(aPlayer.name);
                Player bPlayer = setB.pollFirst();
                while (!setD.contains(bPlayer)) {
                    bPlayer = setB.pollFirst();
                }
                setD.remove(bPlayer);
                team.add(bPlayer.name);
                Player cPlayer = setC.pollFirst();
                while (!setD.contains(cPlayer)) {
                    cPlayer = setC.pollFirst();
                }
                setD.remove(cPlayer);
                team.add(cPlayer.name);
                team.sort(new Comparator<String>() {
                    @Override
                    public int compare(String o1, String o2) {
                        return o1.compareTo(o2);
                    }
                });
                build.append(String.format("%s %s %s", team.get(0), team.get(1), team.get(2)));
                build.append("\n");
            }
        }
        writer.print(build);
        writer.flush();
    }
}

class Player {
    String name;
    long a, b, c;
    Player(String name, long a, long b, long c) {
        this.name = name;
        this.a = a;
        this.b = b;
        this.c = c;
    }
}