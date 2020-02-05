package study;

import java.util.Arrays;
import java.util.concurrent.ThreadLocalRandom;
import java.util.stream.IntStream;

class RadixSort {
    private int[] arr;

    RadixSort(final int size) {
        arr = ThreadLocalRandom.current()
                .ints(size, 0, 1000)
                .toArray();
    }

    RadixSort sort() {
        int maxValue = IntStream.of(arr).max().orElse(0);

        for (int exp = 1; maxValue / exp > 0; exp *= 10) {
            // output 배열은 복사본을 의미, count 배열은 기수정렬할 배열
            int[] output = new int[arr.length];
            int[] count = new int[10];

            // 기수 개수 파악
            for (int value : arr) {
                count[(value / exp) % 10]++;
            }
            // 누적 개수 파악
            for (int i = 1; i < 10; i++) {
                count[i] += count[i - 1];
            }
            // 기수에 따른 정렬
            for (int i = arr.length - 1; i >= 0; i--) {
                output[count[(arr[i] / exp) % 10] - 1] = arr[i];
                count[(arr[i] / exp) % 10]--;
            }

            System.arraycopy(output, 0, arr, 0, arr.length);
        }
        return this;
    }

    void showArray() {
        System.out.println(Arrays.toString(arr));
    }

    public static void main(String[] args) {
        new RadixSort(10)
                .sort()
                .showArray();
    }
}
