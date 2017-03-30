#include "subject.h"
#include "observer.h"
#include "subscriptions.h"
#include <iostream>

void Subject::attach(Observer *o) { 
	observers.emplace_back(o);
}

void Subject::notifyObservers(SubscriptionType t, Info &i) {
	for (auto ob : observers) {
		if (ob->subType() == t) ob->notify(*this, i);
	}
}

void Subject::notifyObservers(SubscriptionType t) {
	for (auto ob : observers) {
		if (ob->subType() == t) ob->notify(*this);
	}	
}