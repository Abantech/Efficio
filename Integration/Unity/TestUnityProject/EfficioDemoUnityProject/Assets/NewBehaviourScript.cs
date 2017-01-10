using UnityEngine;
using System.Collections;
using System;

public class NewBehaviourScript : MonoBehaviour
{
    public TimeSpan timeAfterPinch;

    DateTime resetTime;
    bool coroutineStarted = false;
    bool pinching = false;
    
	void OnPinch ()
    {
        // Do pinch stuff

        // Starts coroutine that eventually releases pinch
        if (!coroutineStarted)
        {
            coroutineStarted = true;
            pinching = true;
            resetTime = DateTime.Now + timeAfterPinch;
            StartCoroutine(OnPinchEnd(OnPinchEnd));
        }
    }

    void OnPinchEnd()
    {

    }

    IEnumerator OnPinchEnd(Action action)
    {
        while (DateTime.Now < resetTime)
        {
            yield return null;
        }

        coroutineStarted = false;
        action();
    }
}
