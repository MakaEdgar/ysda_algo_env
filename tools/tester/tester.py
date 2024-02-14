import click
import glob
import subprocess
from pathlib import Path

@click.group()
def cli() -> None:
    pass

import sys

@click.command()
@click.argument('executable')
@click.option('--timeout', default=5, help='Timeout for a single test.')
# @click.option('-j', default=1, help='Number of parallel tasks.')
def run_cases(executable, timeout) -> None:
    print(executable)
    tests = [Path(x) for x in glob.glob("test_cases/*.in")]
    print(f"Found {len(tests)} tests: {[x.name for x in tests]}.")
    click.echo('\033[93mRunning tests...\033[0m')

    for test in tests:
        click.echo(f"Run test '{test.name}':", nl=False)
        try:
            with open(test, "r") as input:
                out = subprocess.check_output(executable, stdin=input, text=True).strip()

            with open(test.with_suffix(".out"), "r") as true_output:
                if out != true_output.read().strip():
                    click.echo(f" Wrong answer '{out}'.")
                    continue

        except subprocess.CalledProcessError as error:
            click.echo(f" Error happened: {error}.")
            continue
        except subprocess.TimeoutExpired:
            click.echo(f" Timeout({timeout}s).")
            continue

        click.echo(f" Success.")

@click.command()
def run_stress() -> None:
    click.echo('run_stress is not implemented yet.')


cli.add_command(run_cases)
cli.add_command(run_stress)


if __name__ == '__main__':
    cli()