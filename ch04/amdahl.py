#!/usr/bin/env python3
from argparse import ArgumentParser, Namespace


def calc_amdahl(serial: float, parallel: float, cores: int) -> float:
    if not cores:
        raise ZeroDivisionError("Number of cores must be specified")

    if serial:
        if serial < 0. or serial > 1.:
            raise ArithmeticError("Invalid argument for serial, must be decimal percentage")
        parallel = 1. - serial
    else:
        if parallel < 0. or parallel > 1.:
            raise ArithmeticError("Invalid argument for parallel, must be decimal percentage")
        serial = 1. - parallel

    return 1. / (serial + (parallel) / cores)


def parse_args() -> Namespace:
    parser = ArgumentParser(description="Calculator for Amdahl's Law")

    parser.add_argument(
        "--s",
        default=None,
        type=float,
        help="The portion of the application that must be performed serially"
    )
    parser.add_argument(
        "--p",
        default=None,
        type=float,
        help="The portion of the application that can be performed in parallel"
    )
    parser.add_argument(
        "--n",
        default=None,
        type=int,
        help="The number of cores available on the CPU"
    )
    
    return parser.parse_args()


def main() -> None:
    args = parse_args()

    speedup: float = calc_amdahl(serial=args.s, parallel=args.p, cores=args.n)

    print(
        """Speedup for an application which is {:.0f} percent serial and {:.0f} 
        percent parallel on a CPU with {} cores <= {:.2f}""".format(
            args.s * 100. if args.s else 100. * (1.-args.p), 
            args.p * 100. if args.p else 100. * (1.-args.s), 
            args.n, speedup
        )
    )


if __name__ == "__main__":
    main()
