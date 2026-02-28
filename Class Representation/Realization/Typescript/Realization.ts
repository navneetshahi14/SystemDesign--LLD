interface Flyable {
    fly(): void;
    getFlightInfo(): string;
}

class Bird implements Flyable {
    private species: string;
    private wingSpan: number;

    constructor(species: string, wingSpan: number) {
        this.species = species;
        this.wingSpan = wingSpan;
    }

    fly(): void {
        console.log(`${this.species} flaps its wings and takes off.`);
    }

    getFlightInfo(): string {
        return `${this.species} (wingspan: ${this.wingSpan}m, powered by muscle)`;
    }
}

class Airplane implements Flyable {
    private model: string;
    private maxAltitude: number;

    constructor(model: string, maxAltitude: number) {
        this.model = model;
        this.maxAltitude = maxAltitude;
    }

    fly(): void {
        console.log(`${this.model} engines roar as it accelerates down the runway.`);
    }

    getFlightInfo(): string {
        return `${this.model} (max altitude: ${this.maxAltitude}ft, powered by jet engines)`;
    }
}

class Drone implements Flyable {
    private batteryLevel: number;
    private maxRange: number;

    constructor(batteryLevel: number, maxRange: number) {
        this.batteryLevel = batteryLevel;
        this.maxRange = maxRange;
    }

    fly(): void {
        console.log(`Drone propellers spin up. Battery at ${this.batteryLevel}%.`);
    }

    getFlightInfo(): string {
        return `Drone (range: ${this.maxRange}km, battery: ${this.batteryLevel}%)`;
    }
}

function main(): void {
    const flyingThings: Flyable[] = [
        new Bird("Eagle", 2.3),
        new Airplane("Boeing 737", 41000),
        new Drone(85, 10.0),
    ];

    for (const flyer of flyingThings) {
        console.log(flyer.getFlightInfo());
        flyer.fly();
        console.log();
    }
}

main();