use std::{sync::{Arc, atomic::AtomicBool, mpsc::{self, Sender, Receiver}, Mutex}, thread};

use rand::Rng;

fn main() {
    // default to 8 threads but take whatever they give
    let n = 8;
    let mut rng = rand::thread_rng();
    let mut children = Vec::with_capacity(8);
    let spinner = Arc::new(Mutex::new(vec![0;n]));
    let cupcake = Arc::new(AtomicBool::new(true));
    let first = rng.gen_range(0..n);
    let initial = true;

    println!("running with {} threads", n);

    for id in 0..n {
        let cupcake_copy = Arc::clone(&cupcake);
        let spin2win = Arc::clone(&spinner);
        let child;
        spinner.lock().unwrap().push(0);

        if initial {
            // the cupcake consumer
            // they're counting however many cupcakes they eat
            // when they count n cupcakes they know that everyone's gone through
            child = thread::spawn(move || {
                let count = 0u8; 
                // cupcake_copy.compare_exchange(true, false, , failure);

                println!("thread {} finished", id);
            });
            initial = false;
            
        }
        else {
            child = thread::spawn(move || {
                let ate_cupcake = false;
                while(k)
                println!("thread {} finished", id);
            });
        }


        children.push(child);

    }

    while spinner.lock().unwrap() {

    }

}
