package java;

/** Singleton pattern */
public class Q2 {

}

/** Single thread, lazy pattern */
class Singleton {
    private static Singleton instance;

    private Singleton() {
    }

    public static Singleton getInstance() {
        if (instance == null) {
            instance = new Singleton();
        }
        return instance;
    }
}

/** Hungry pattern, thread safe */
class Singleton1 {

    // reference to an instance of self class but waste memory
    private static final Singleton1 instance = new Singleton1();

    private Singleton1() {
    }

    public static Singleton1 getInstance() {
        return instance;
    }
}

/** Lazy pattern, thread safe */
class Singleton2 {
    private static Singleton2 instance;

    private Singleton2() {
    }

    // lock but expensive due to lock(synchronized)
    public static synchronized Singleton2 getInstance() {
        if (instance == null) {
            instance = new Singleton2();
        }
        return instance;
    }
}

/**
 * Double checked locking (DCL):
 * Only add lock when it's first time trying to create instance (when is null),
 * after instance is created, there is no need using lock to protect thread safe
 * because instacne now can be concurrently read.
 * In this way, higher efficiency
 * 
 * (protect when first-time written, not protected when read)
 */
class Singleton3 {
    private static Singleton3 instance;

    private Singleton3() {
    }

    public static Singleton3 getInstance() {
        if (instance == null) {
            synchronized (Singleton3.class) {
                if (instance == null)
                    instance = new Singleton3();
            }
        }
        return instance;
    }
}